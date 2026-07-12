<div align="center">

# 🏰 TowerDefense

**Prototyp gry Tower Defense napisany w C++ z wykorzystaniem biblioteki SFML**

![C++](https://img.shields.io/badge/C%2B%2B-Game_Dev-00599C?logo=cplusplus&logoColor=white)
![SFML](https://img.shields.io/badge/SFML-2.x-8CC445?logo=sfml&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual_Studio-Solution-5C2D91?logo=visualstudio&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?logo=windows&logoColor=white)

</div>

---

## 🎯 O projekcie

Prototyp klasycznej gry tower defense zbudowany od podstaw w **C++/SFML**.
Projekt jest podzielony na dwie warstwy:

- **GameBase** — własny mini-silnik / warstwa frameworka: pętla gry (`GameManager`),
  obsługa wejścia (`InputManager`, `KeyHandler`, `MouseHandler`) i zdarzeń
- **TowerDefense** — logika samej gry: `TowerDefenseGame`, `PlayerControls`, `EventsHandler`

```
proj/TowerDefense/
├── GameBase/         # Silnik: GameManager, InputManager, Key/MouseHandler, API
└── TowerDefense/     # Gra: TowerDefenseGame, PlayerControls, EventsHandler, main
include/ & lib/       # Nagłówki i biblioteki SFML
bin/                  # Binaria / zasoby
```

## 🚀 Budowanie

1. Otwórz `proj/TowerDefense/TowerDefense.sln` w **Visual Studio**
2. Wybierz konfigurację (Debug/Release) i zbuduj solucję — SFML jest dołączony w `include/` i `lib/`
3. Uruchom projekt `TowerDefense`

## 👤 Autor

[**Mateusz Janecki**](https://github.com/JaneckiGit) · 🌐 [janeckimateusz.com](https://janeckimateusz.com) · [LinkedIn](https://www.linkedin.com/in/mateusz-j-621b1a196/)
