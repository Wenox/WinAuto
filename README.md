# WinAuto

**WinAuto** is a powerful CLI-based automation tool for Windows that lets you record and replay keyboard and mouse actions. Originally developed as an innovative university project, WinAuto is designed to simplify repetitive tasks by mimicking user input with exceptional precision and efficiency.

## Overview

WinAuto captures your interactions with the computer, including **cursor movements, mouse clicks, and keyboard presses**. These actions are recorded in real-time and stored in a highly efficient queue-based data structure for flawless playback. Whether for automation or testing, WinAuto ensures precise reproduction of recorded actions.

## Features

- **Real-Time Recording and Playback:** Capture and replay your keyboard and mouse actions with high fidelity.
- **Persistence:** Save and load recordings to/from `.txt` files, allowing you to reuse and share your recorded actions easily.
- **Infinite Loop:** Option to playback recordings in an infinite loop until manually stopped.
- **Smooth Cursor Movement:** Ensures fluid and visually appealing transitions during playback, mimicking real movement.
- **Efficient Data Management:** Uses a doubly linked list with conditional cyclic properties to optimize memory usage.
- **Accurate Timing:** Ensures the recordings and playbacks maintain the same duration.
- **Customizable Hotkeys:** Set your own hotkeys to control the recording and playback processes.
- **Screensaver Mode:** A fun screensaver feature that moves the cursor randomly to prevent unauthorized use.

## Data Structures

- **Priority Queue:** An array-based priority queue for keystrokes, optimized for fast access based on the frequency of use.
- **Doubly Linked List:** The core data structure used to store recorded actions, capable of transforming into a cyclic list for infinite playback loops.

## Usage

1. **Set Hotkey:** Define a global hotkey to control the recording and playback processes.
2. **Create New Recording:** Start recording your actions, which will be saved to a specified `.txt` file.
3. **Playback Recording:** Load a saved recording and replay it as many times as needed.
4. **Screensaver Mode:** Activate the screensaver to prevent unauthorized access when you're away from the computer.
5. **Exit:** Close the application safely.
