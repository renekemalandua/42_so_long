# 🟡 42\_so\_long

A 42 School project: recreate a simplified Pac-Man–style game, demonstrating real-time logic, map parsing, event handling, and algorithmic problem-solving.
Built with **C, MinilibX, and Libft**.

---

## 🎮 How to Play

* The player is represented by **Pac-Man**.
* Your objective:

  * Collect **all the coins (C)** on the map.
  * Reach the **exit (E)** to win.
* The map must be valid:

  * Surrounded by walls (`1`)
  * Contains at least one **player (P)**, one **exit (E)**, and one or more **collectibles (C)**.
  * Must be rectangular.

---

## 🕹️ Controls

* **Arrow keys** or **W/A/S/D** to move:

  * `↑` / `W` → Move up
  * `↓` / `S` → Move down
  * `←` / `A` → Move left
  * `→` / `D` → Move right
* **ESC** → Quit the game.

Each move increments the **move counter** shown in the terminal.

---

## ⚙️ Compilation & Run

Clone the repository and compile:

```bash
make
```

Run the game with a `.ber` map file:

```bash
make run
```

---

## 🗺️ Map Rules

* Valid characters:

  * `1` → Wall
  * `0` → Empty space
  * `P` → Player start position
  * `C` → Collectible coin
  * `E` → Exit

Example of a valid map:

```
111111
1P0C01
1000E1
111111
```

---

## 🛠️ Features

* Real-time event handling (keyboard input).
* Map parsing and validation.
* Dynamic rendering with MinilibX.
* Pac-Man style player animation.
* Error handling for invalid maps.

---

## 🚀 Bonus Ideas (if implemented)

* Enemies chasing the player.
* More complex animations.
* Multiple maps selectable from menu.

---

## 📌 Notes

* Project developed as part of **42 School curriculum**.
* Runs on Linux with **MinilibX**.
* Inspired by the classic **Pac-Man** but simplified to match project requirements.
