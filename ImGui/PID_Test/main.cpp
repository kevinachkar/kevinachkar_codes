#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

// ---------------- MAIN ----------------
int main() {

    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1000, 650, "Modern ImGui App", NULL, NULL);
    if (!window)
        return -1;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // ---------------- STYLE ----------------
    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 10.0f;
    style.FrameRounding = 6.0f;
    style.ScrollbarRounding = 8.0f;

    // Custom accent color (orange / red-ish instead of blue)
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_Button]        = ImVec4(0.90f, 0.35f, 0.15f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.45f, 0.20f, 1.00f);
    colors[ImGuiCol_ButtonActive]  = ImVec4(0.80f, 0.25f, 0.10f, 1.00f);

    colors[ImGuiCol_FrameBg]       = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]= ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);

    // ---------------- BACKEND ----------------
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // ---------------- VARIABLES ----------------
    float sliderValue = 0.5f;
    float numberA = 10.0f;
    float numberB = 20.0f;

    char textInput[128] = "Hello ImGui";

    bool toggle = false;

    // ---------------- LOOP ----------------
    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        // Start frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ---------------- UI ----------------
        ImGui::Begin("Control Panel");

        ImGui::Text("Modern ImGui Example UI");
        ImGui::Separator();

        // Slider
        ImGui::SliderFloat("Main Slider", &sliderValue, 0.0f, 1.0f);

        // Input numbers
        ImGui::InputFloat("Value A", &numberA);
        ImGui::InputFloat("Value B", &numberB);

        // Text input
        ImGui::InputText("Text Box", textInput, 128);

        ImGui::Separator();

        // Buttons
        if (ImGui::Button("Apply")) {
            numberB = numberA * sliderValue;
        }

        ImGui::SameLine();

        if (ImGui::Button("Reset")) {
            sliderValue = 0.5f;
            numberA = 10.0f;
            numberB = 20.0f;
        }

        // Toggle button
        if (ImGui::Checkbox("Enable System", &toggle)) {
            // could enable PID / robot / simulation here
        }

        ImGui::Separator();

        ImGui::Text("Output:");
        ImGui::Text("Result = %.2f", numberB);

        ImGui::End();

        // ---------------- RENDER ----------------
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);
        glClearColor(0.12f, 0.12f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // ---------------- CLEANUP ----------------
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}