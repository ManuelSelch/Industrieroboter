# Industrieroboter

Projekt zur Kommunikation eines Microcontrollers (C++) mit einem Industrieroboter (V+)
<br><br>
- Der Microcontroller (ein NodeMCU mit ESP Chip) liest aktuelle Befehle des Webservers aus
- Die Befehle werden dann an den Industrieroboter gemorst
- Dies soll in beide Richtugen funktinieren:
a) Bspw. Sensordaten Übermittlung an Industrieroboter
b) Befehle des Industrieroboters an den Arduino

# Master-Slave Prinzip:

Die komplette Logik soll auf dem Industrieroboter erfolgen (V+) und der Arduino sendet nur angeforderte Sensordaten oder führt Befehle aus
