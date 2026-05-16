#include <cmath>

// ImGui + GLFW + OpenGL
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

// ---------------- PID STRUCT ----------------
struct PID {
    float kp = 0.0f;
    float ki = 0.0f;
    float kd = 0.0f;

    float prevError = 0.0f;
    float integral = 0.0f;

    float update(float target, float current, float dt) {
        float error = target - current;

        integral += error * dt;
        float derivative = (error - prevError) / dt;

        prevError = error;

        return kp * error + ki * integral + kd * derivative;
    }
};

// ---------------- MAIN ----------------
int main() {

    // GLFW init
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(1000, 700, "3-Cascade PID Test", NULL, NULL);
    if (!window) return -1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // ImGui setup
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // ---------------- SYSTEM STATE ----------------
    float dt = 0.016f;

    float target = 50.0f;

    float level1 = 0.0f;  // outer loop output
    float level2 = 0.0f;  // middle loop output
    float level3 = 0.0f;  // inner loop (final system state)

    float velocity = 0.0f;

    // ---------------- 3 PID LOOPS ----------------
    PID pid_outer;
    PID pid_mid;
    PID pid_inner;

    // Graph buffer
    float graph[200] = {0};
    int index = 0;

    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        // ================= CASCADED PID =================
        // Outer loop: target -> level1
        float out1 = pid_outer.update(target, level1, dt);

        // Middle loop: level1 -> level2
        float out2 = pid_mid.update(out1, level2, dt);

        // Inner loop: level2 -> level3 (actual system control)
        float control = pid_inner.update(out2, level3, dt);

        // ================= PHYSICS SIM =================
        velocity += control * dt;
        velocity *= 0.98f; // damping
        level3 += velocity * dt;

        // slight coupling to create more realistic cascade behavior
        level2 += (level3 - level2) * 0.05f;
        level1 += (level2 - level1) * 0.05f;

        // ================= GRAPH =================
        graph[index] = level3;
        index = (index + 1) % 200;

        // ================= UI =================
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("3 Cascaded PID Controller");

        ImGui::Text("Target: %.2f", target);

        ImGui::SliderFloat("Target", &target, -100, 100);

        ImGui::Separator();

        ImGui::Text("Outer PID");
        ImGui::SliderFloat("Kp Outer", &pid_outer.kp, 0, 5);
        ImGui::SliderFloat("Ki Outer", &pid_outer.ki, 0, 2);
        ImGui::SliderFloat("Kd Outer", &pid_outer.kd, 0, 5);

        ImGui::Text("Middle PID");
        ImGui::SliderFloat("Kp Mid", &pid_mid.kp, 0, 5);
        ImGui::SliderFloat("Ki Mid", &pid_mid.ki, 0, 2);
        ImGui::SliderFloat("Kd Mid", &pid_mid.kd, 0, 5);

        ImGui::Text("Inner PID");
        ImGui::SliderFloat("Kp Inner", &pid_inner.kp, 0, 5);
        ImGui::SliderFloat("Ki Inner", &pid_inner.ki, 0, 2);
        ImGui::SliderFloat("Kd Inner", &pid_inner.kd, 0, 5);

        ImGui::Separator();

        ImGui::Text("Level 1: %.2f", level1);
        ImGui::Text("Level 2: %.2f", level2);
        ImGui::Text("Level 3 (output): %.2f", level3);

        ImGui::PlotLines("System Response", graph, 200);

        ImGui::End();

        // ================= RENDER =================
        ImGui::Render();

        int w, h;
        glfwGetFramebufferSize(window, &w, &h);

        glViewport(0, 0, w, h);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}