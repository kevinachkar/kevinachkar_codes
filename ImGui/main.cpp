#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>

int main()
{
    glfwInit();

    GLFWwindow* window =
        glfwCreateWindow(1500, 900, "", NULL, NULL);

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // UI goes here // Thats where i write everything(btns,sliders,text..........)
        ImGui::Begin("Main", nullptr,
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoTitleBar
);

ImGui::SetWindowPos(ImVec2(0, 0));
ImGui::SetWindowSize(ImGui::GetIO().DisplaySize);

static int page = 0;

// LEFT MENU
ImGui::BeginChild("Menu", ImVec2(200, 0), true);

if (ImGui::Button("Control")) page = 0;
if (ImGui::Button("Settings")) page = 1;
if (ImGui::Button("Sensors")) page = 2;

ImGui::EndChild();

// RIGHT CONTENT AREA
ImGui::SameLine();

ImGui::BeginChild("Content", ImVec2(0, 0), true);

if (page == 0)
{
    ImGui::Text("CONTROL PANEL");

    static float speed = 5.0f;
    ImGui::SliderFloat("Speed", &speed, 0.0f, 10.0f);
}

if (page == 1)
{
    ImGui::Text("SETTINGS");

    static float gain = 1.0f;
    ImGui::InputFloat("Gain", &gain);
}

if (page == 2)
{
    ImGui::Text("SENSORS");
    ImGui::Text("IMU DATA HERE");
}

ImGui::EndChild();

ImGui::End();
        /////////////////

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(
            ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}