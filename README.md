# Deep Miner

Deep Miner ist ein simuliertes Bergbau-Spiel, bei dem Spieler einen Roboter steuern, um Ressourcen in einem dreidimensionalen Spielfeld abzubauen. Das Ziel des Spiels ist es, alle verfügbaren Ressourcen abzubauen und dabei verschiedene Herausforderungen zu meistern.

## Spielbeschreibung

Bei Spielstart wählt der Spieler einen von drei verschiedenen Robotern, die jeweils einzigartige Fähigkeiten besitzen. Das Spielfeld ist ein dreidimensionales Gitter, in dem verschiedene Ressourcen versteckt sind. Spieler müssen strategisch vorgehen, um die Ressourcen effizient abzubauen, Punkte zu sammeln und die Spielziele zu erreichen.

## Struktur

Das Projekt ist in mehrere Module unterteilt:

- **GameManager**: Verwaltet den Spielablauf, einschließlich der Initialisierung des Spiels und der Steuerung des Spielzyklus.
- **GameWorld**: Verantwortlich für die Darstellung des Spielfelds und die Verwaltung der Spiellogik.
- **Robot**: Eine abstrakte Basisklasse für die Roboter, die von den Spielern gesteuert werden.
- **Robot1**, **Robot2**, **Robot3**: Spezialisierungen der Robot-Klasse, die unterschiedliche Fähigkeiten und Strategien für das Spiel implementieren.

## Vorraussetzungen

- C++ Compiler

## Spielanleitung

- **Roboterwahl**: Zu Beginn des Spiels wählen Sie einen von drei Robotern aus. Jeder Roboter hat einzigartige Fähigkeiten.
- **Navigation**: Bewegen Sie den Roboter durch das Spielfeld, um Ressourcen abzubauen. Nutzen Sie die Steuerungsbefehle (w, a, s, d) für die Bewegung.
- **Ressourcenabbau**: Ziel ist es, alle verfügbaren Ressourcen effizient abzubauen und dabei Punkte zu sammeln.
- **Spezialfelder**: Achten Sie auf die Spezialfelder mit besonderen Effekten:
    - **Effektfeld '1'**: Verhindert den Abbau in der aktuellen Runde.
    - **Effektfeld '2'**: Teleportiert den Roboter zum niedrigsten Wert im Spielfeld.
    - **Effektfeld '3'**: Verdoppelt die Punkte des Roboters.
- **Spielziel**: Das Ziel des Spiels ist es, alle Felder abzubauen und die höchstmögliche Punktzahl zu erreichen.
