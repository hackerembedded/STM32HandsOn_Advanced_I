# STM32 Hands-On – Advanced I

Advanced hands-on training material for **STM32 embedded systems development**, focused on practical development workflows, debugging, RTOS, bootloaders, graphics, security, and Edge AI.

This repository is designed for developers who already have basic STM32 experience and want to explore more advanced topics using real-world embedded development techniques.

## Overview

The **STM32 Hands-On – Advanced I** course provides a collection of practical labs covering several areas of modern STM32 development:

* Advanced development using **Visual Studio Code**
* **CMake** based STM32 projects
* **STM32Cube for VS Code**
* **Serial Wire Viewer (SWV)** and advanced debugging
* **FreeRTOS**
* Tasks, queues, mutexes and semaphores
* External interrupts and peripheral handling
* Bootloaders and firmware update concepts
* CRC and firmware integrity
* Touch sensing and graphics
* Security
* Edge AI and Human Activity Recognition
* NanoEdge AI based machine learning
* Practical AI data acquisition and deployment

The examples are primarily based on the **STM32F4** family and are intended to be used as hands-on exercises rather than as a generic STM32 software library.

---

## Repository Structure

The repository is organized as a collection of independent labs and supporting projects.

### Development Environment Legend

| Symbol | Build System / IDE     | Recommended Environment                                  |
| ------ | ---------------------- | -------------------------------------------------------- |
| 🟢     | **CMake**              | **Visual Studio Code + STM32Cube for VS Code extension** |
| 🔵     | **Makefile / Eclipse** | **STM32CubeIDE**                                         |
| 🟡     | Supporting material    | Depends on the specific activity                         |

> **Important:** The projects intentionally use different STM32 development workflows. Before opening a project, check the **Development Environment** column and use the corresponding toolchain.

### Projects

| Project                      | Topic                                        | Build System           | Development Environment           |
| ---------------------------- | -------------------------------------------- | ---------------------- | --------------------------------- |
| `EmptyProject/STM32F4_Empty` | Minimal STM32F4 project template             | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabUART`                    | UART communication                           | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabEXTI`                    | External interrupts                          | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabSWV`                     | Serial Wire Viewer / advanced debugging      | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabTasks`                   | FreeRTOS tasks                               | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabQueue`                   | FreeRTOS queues                              | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabMutex`                   | FreeRTOS mutexes                             | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabSemaphore`               | FreeRTOS semaphores                          | 🟢 CMake               | **VS Code + STM32Cube extension** |
| `LabLinker`                  | Linker scripts and memory organization       | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabApp`                     | STM32 application development                | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabBoot`                    | Bootloader development                       | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabCRC`                     | CRC and firmware integrity                   | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabChallenge`               | Practical embedded challenge                 | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `Lab1GUI`                    | Graphics / GUI development                   | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabOpenBoot`                | OpenBootloader                               | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabTSC`                     | Touch Sensing Controller                     | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabTSC_TestColor`           | Touch / display test                         | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabTSC_SwapScreens`         | Touch / display screen management            | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabAIHAR_datalog`           | AI data acquisition                          | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabAIHAR_part1`             | Human Activity Recognition – Part 1          | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabAIHAR_part2`             | Human Activity Recognition – Part 2          | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `LabAINanoEdge`              | NanoEdge AI                                  | 🔵 Makefile / Eclipse  | **STM32CubeIDE**                  |
| `Homework_NanoEdge`          | NanoEdge AI homework / datasets              | 🟡 Supporting material | **See activity instructions**     |
| `LabAI_HAR`                  | Human Activity Recognition model development | 🟡 Python / Jupyter    | **Jupyter Notebook / Python**     |

---

## 🟢 CMake Projects — Visual Studio Code

The CMake-based labs are intended to demonstrate a modern embedded development workflow using **Visual Studio Code together with the STM32Cube for VS Code extension**.

These projects use the CMake-based project infrastructure required by this workflow, such as:

```text
CMakeLists.txt
CMakePresets.json
cmake/
.vscode/
```

### CMake / VS Code Projects

* `EmptyProject/STM32F4_Empty`
* `LabUART`
* `LabEXTI`
* `LabLinker`
* `LabSWV`
* `LabTasks`
* `LabQueue`
* `LabMutex`
* `LabSemaphore`

For these projects:

1. Open the project folder in **Visual Studio Code**.
2. Install and use the **STM32Cube for VS Code extension**.
3. Use the CMake configuration supplied with the project.
4. Configure, build and debug the firmware from the VS Code environment.

> **Do not import these projects as traditional Eclipse projects into STM32CubeIDE.** They are intended to demonstrate the CMake + VS Code workflow.

---

## 🔵 STM32CubeIDE Projects

The remaining firmware labs use the traditional **STM32CubeIDE / Eclipse-based project structure**.

These projects should be imported into **STM32CubeIDE** rather than being treated as CMake projects in VS Code.

### STM32CubeIDE Projects

* `LabApp`
* `LabBoot`
* `LabCRC`
* `LabChallenge`
* `Lab1GUI`
* `LabOpenBoot`
* `LabTSC`
* `LabTSC_TestColor`
* `LabTSC_SwapScreens`
* `LabAIHAR_datalog`
* `LabAIHAR_part1`
* `LabAIHAR_part2`
* `LabAINanoEdge`

For these projects:

1. Open **STM32CubeIDE**.
2. Import the project into your workspace.
3. Allow STM32CubeIDE to recognize the existing project structure.
4. Build and debug using the STM32CubeIDE toolchain.

> **Do not try to configure these projects as CMake projects in VS Code.** They are intended to demonstrate the traditional STM32CubeIDE workflow.

---

## 🟡 Supporting / AI Material

Some directories are not conventional STM32 firmware projects and therefore don't belong to either IDE category.

For example, `LabAI_HAR` contains the Human Activity Recognition model-development material rather than a conventional STM32 IDE project.

These activities use:

* Python
* Jupyter Notebook
* TensorFlow
* TensorFlow Lite
* Machine Learning
* Dataset preparation
* Model training and evaluation

---

## Choosing the Correct Development Environment

Before starting a lab, use the following rule:

```text
                     STM32 Hands-On Lab
                            │
                            ▼
                 Check the project table
                            │
             ┌──────────────┴──────────────┐
             │                             │
             ▼                             ▼
       🟢 CMake project              🔵 CubeIDE project
             │                             │
             ▼                             ▼
     Visual Studio Code             STM32CubeIDE
             │                             │
             ▼                             ▼
     STM32Cube extension          Eclipse / Makefile
             │                             │
             └──────────────┬──────────────┘
                            ▼
                       Build & Debug
```

### Quick Reference

| If the project is...      | Use...                                       |
| ------------------------- | -------------------------------------------- |
| 🟢 **CMake**              | **Visual Studio Code + STM32Cube extension** |
| 🔵 **Makefile / Eclipse** | **STM32CubeIDE**                             |
| 🟡 **Python / Jupyter**   | **Python + Jupyter Notebook**                |

> **Do not mix the workflows.** If a lab is marked **CMake**, use **VS Code + STM32Cube extension**. If a lab is marked **Makefile / Eclipse**, import and build it using **STM32CubeIDE**.

---

## Learning Path

A suggested progression through the material is:

### 1. Development Environment

Start with the basic project and development environment:

* `EmptyProject/STM32F4_Empty`
* `LabUART`
* `LabEXTI`
* `LabLinker`

These projects provide the foundation for understanding STM32 project organization, peripherals, interrupts and memory layout.

### 2. Advanced Debugging

Continue with:

* `LabSWV`

This lab introduces **Serial Wire Viewer (SWV)** and advanced debugging capabilities, providing visibility into the internal behavior of an embedded application without relying exclusively on traditional UART logging.

### 3. FreeRTOS

The repository includes several labs dedicated to RTOS concepts:

* `LabTasks`
* `LabQueue`
* `LabMutex`
* `LabSemaphore`

Together these exercises demonstrate fundamental FreeRTOS mechanisms including:

* Tasks
* Task scheduling
* Inter-task communication
* Queues
* Mutexes
* Semaphores
* Resource synchronization

### 4. Bootloader and Firmware

The bootloader section includes:

* `LabBoot`
* `LabCRC`
* `LabOpenBoot`

These exercises introduce concepts such as:

* Application / bootloader separation
* STM32 memory organization
* Firmware validation
* CRC
* Firmware update mechanisms
* OpenBootloader

### 5. Graphics and Touch

The repository also contains hands-on examples involving:

* GUI development
* Touch sensing
* Display interaction

Relevant projects include:

* `Lab1GUI`
* `LabTSC`
* `LabTSC_TestColor`
* `LabTSC_SwapScreens`

### 6. Edge AI

The final section introduces embedded machine learning using Human Activity Recognition and NanoEdge AI.

The AI workflow covers the typical embedded AI development cycle:

```text
Sensor Data
     ↓
Data Acquisition
     ↓
Dataset
     ↓
Model Training
     ↓
Model Evaluation
     ↓
Embedded Deployment
     ↓
STM32 Application
```

The Human Activity Recognition material includes data acquisition, dataset preparation, model development and embedded deployment.

Relevant projects include:

* `LabAI_HAR`
* `LabAIHAR_datalog`
* `LabAIHAR_part1`
* `LabAIHAR_part2`
* `LabAINanoEdge`
* `Homework_NanoEdge`

---

## Development Tools

### STM32CubeMX

Used to configure:

* MCU peripherals
* Clock tree
* GPIO
* Interrupts
* Middleware
* FreeRTOS
* Project generation

Several projects include `.ioc` configuration files generated by STM32CubeMX.

### Visual Studio Code + STM32Cube Extension

The CMake-based projects use **Visual Studio Code** together with the **STM32Cube for VS Code extension**.

This workflow provides:

* Source code editing
* CMake configuration
* Building
* Debugging
* STM32 project configuration
* Embedded development
* SWV-based debugging

### STM32CubeIDE

The Eclipse-based projects use **STM32CubeIDE** and its integrated build and debugging environment.

This workflow provides:

* STM32CubeMX integration
* Eclipse-based project management
* Makefile-based builds
* Source code editing
* Debugging
* ST-LINK integration
* STM32 firmware development

### CMake

The VS Code projects use CMake infrastructure such as:

* `CMakeLists.txt`
* `CMakePresets.json`
* `cmake/`

CMake is used here to demonstrate a modern, IDE-independent build system integrated with the STM32Cube VS Code development environment.

---

## Hardware

The labs are primarily designed around **STM32F4-class microcontrollers**.

The exact hardware requirements may vary between labs.

A typical setup may include:

* STM32F4 development board
* ST-LINK debugger/programmer
* USB connection
* Sensors or peripherals required by individual labs
* Display / touch hardware for graphics exercises

> **Note:** Check the individual lab configuration before running it on different STM32 devices. Pin assignments, memory maps, peripherals and linker scripts may be device-specific.

---

## Getting Started

Clone the repository:

```bash
git clone https://github.com/hackerembedded/STM32HandsOn_Advanced_I.git
```

Enter the repository:

```bash
cd STM32HandsOn_Advanced_I
```

Choose one of the labs and check the **Development Environment** column in the project table.

### CMake / VS Code Example

For a CMake project:

```text
LabSWV/
LabTasks/
LabQueue/
LabMutex/
LabSemaphore/
```

Open the selected project folder in **Visual Studio Code** and use the **STM32Cube for VS Code extension** to configure, build and debug the project.

### STM32CubeIDE Example

For a traditional STM32CubeIDE project:

```text
LabBoot/
LabCRC/
LabOpenBoot/
Lab1GUI/
```

Import the project into **STM32CubeIDE** and use the integrated build and debug tools.

---

## Recommended Prerequisites

This repository is intended for **intermediate to advanced embedded developers**.

Before starting, it is recommended to have basic knowledge of:

* C programming
* STM32 microcontrollers
* ARM Cortex-M architecture
* GPIO
* Timers
* UART
* Interrupts
* STM32CubeMX
* STM32 HAL
* Basic debugging with ST-LINK

For the RTOS labs, basic knowledge of **FreeRTOS** is helpful.

For the AI labs, familiarity with:

* Python
* Jupyter Notebook
* Machine Learning concepts
* TensorFlow / TensorFlow Lite

will make the exercises easier to follow.

---

## Course Philosophy

The goal of this repository is not simply to provide working firmware.

The labs are designed to help developers understand the **engineering decisions behind embedded software**, including:

```text
Hardware
   │
   ├── MCU peripherals
   ├── Interrupts
   ├── Memory
   └── Debug interface
          │
          ▼
Software Architecture
   │
   ├── HAL
   ├── FreeRTOS
   ├── Bootloader
   ├── Middleware
   └── Application
          │
          ▼
Advanced Features
   │
   ├── Graphics
   ├── Security
   └── Edge AI
```

The intention is to move from **peripheral-level programming** toward complete embedded application architectures.

---

## Repository Contents

In addition to the individual labs, the repository includes supporting resources such as:

* NanoEdge AI datasets
* AI model files
* TouchGFX project packages
* OpenBootloader resources
* S-record utilities
* Supporting archives and project files

These resources are provided to support the corresponding hands-on activities.

---

## Related Material

For additional STM32 and embedded development content:

* [Hacker Embedded](https://hackerembedded.com/)
* [Hacker Embedded on GitHub](https://github.com/hackerembedded)

---

## License

This repository is released under the **GNU General Public License v3.0 (GPL-3.0)**.

See the [`LICENSE`](LICENSE) file for the complete license terms.

---

## Author

**Hacker Embedded**

Practical embedded systems development, STM32, RTOS, security and Edge AI.

* [GitHub](https://github.com/hackerembedded)
* [Website](https://hackerembedded.com/)

---

## Disclaimer

The examples in this repository are provided for educational and development purposes.

Always verify the configuration, memory layout, peripheral assignments and hardware compatibility before using any example in a production system.
