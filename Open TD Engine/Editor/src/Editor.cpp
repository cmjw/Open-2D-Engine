#include "Editor.h"

Editor::Editor() {
	initialize();
}

Editor::~Editor() {
	cleanup();
}

void Editor::initialize() {
	// Get desktop resolution
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

	window.create(sf::VideoMode(desktopMode.width, desktopMode.height), "Game Editor", sf::Style::Default);

	// Initialize ImGui-SFML
	ImGui::SFML::Init(window);

	// Clock to manage frame rate
	sf::Clock deltaClock;

	// Default to dark mode
	isDarkMode = true;
	ImGui::StyleColorsDark();

	// Maximize the window
	window.setPosition(sf::Vector2i(0, 0));
	window.setSize(sf::Vector2u(desktopMode.width, desktopMode.height));
}

void Editor::render() {
	window.clear();
	ImGui::SFML::Render(window);
	window.display();
}

void Editor::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            ImGui::SFML::ProcessEvent(event);
        }

        // Start the ImGui frame
        ImGui::SFML::Update(window, deltaClock.restart());

		initMenubar();

        // Create a main content area
        ImGui::Begin("Game Editor");
        ImGui::Text("Welcome to the Game Editor!");
        ImGui::Text("Use the File menu to run the engine.");
        ImGui::End();

		render();
    }
	cleanup();
}

void Editor::initMenubar() {
	// Create a menu bar
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Load Project")) {
                    // Load a project/data folder
                }
                if (ImGui::MenuItem("Save")) {
                    // Save the current data folder 
                }
                if (ImGui::MenuItem("Close Project")) {

                }
                if (ImGui::MenuItem("Exit")) {
                    window.close();
                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Edit")) {
                if (ImGui::MenuItem("Undo")) {
                    // todo 
                }
                if (ImGui::MenuItem("Redo")) {

                }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("View")) {
                if (ImGui::MenuItem("Toggle Dark/Light Mode")) {
                    // Switch between light and dark mode
                    isDarkMode = !isDarkMode;
                    if (isDarkMode) {
                        ImGui::StyleColorsDark();
                    }
                    else {
                        ImGui::StyleColorsLight();
                    }
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Playtest")) {
                STARTUPINFO si;
                PROCESS_INFORMATION pi;

                // Zero out the structures
                ZeroMemory(&si, sizeof(si));
                si.cb = sizeof(si);
                ZeroMemory(&pi, sizeof(pi));

                // Start the process using a relative path
                if (CreateProcess(
                    "Engine.exe",  // Relative path to your executable
                    NULL,              // Command line arguments
                    NULL,              // Process handle not inheritable
                    NULL,              // Thread handle not inheritable
                    FALSE,             // Do not inherit handles
                    0,                 // No creation flags
                    NULL,              // Use parent's environment block
                    NULL,              // Use parent's starting directory 
                    &si,               // Pointer to STARTUPINFO structure
                    &pi)               // Pointer to PROCESS_INFORMATION structure
                    ) {
                    // Successfully started the process
                    CloseHandle(pi.hProcess);
                    CloseHandle(pi.hThread);
                }
                else {
                    MessageBox(NULL, "Failed to launch the executable", "Error", MB_OK | MB_ICONERROR);
                }
            }
            ImGui::EndMainMenuBar();
        }
}

void Editor::cleanup() {
	ImGui::SFML::Shutdown();
}