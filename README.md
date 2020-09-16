# C Crashkurs

---

Created: 2020/09/16 21:21:48
Last modified: 2020/09/16 21:37:12
Version: 0.0.0-beta

---

Crashkurs zur Vorlesung Betriebssystem an der Hochschule Heilbronn im Studiengang  Software Engineering Bachelor (SEB). 

[Dialog](#Dialog)
[Grundlagen](#grundlagen)
[Funktionen](#funktionen)
[Pointers](#pointers)
[Datenstrukturen](#datenstrukturen)
[C-Bibliotheken](#bibliotheken)
[Anhang 
[C Style Guide](#c-style-guide)

## Ein Dialog über C


**Professor:** *Systemnahe Programmierung findet oft mittels der Programmiersprach C statt. Urspung hat C in der Entwicklung des UNIX Kernels, der zuvor direkt mit Assembler entwicklet wurde. Gegen Ende des 20 Jhd. wurden zahlreiche Programme in C entwickelt. Neben UNIX entwicklete Oracle seine Datenbanken in C und auch Windows 1.0 wurde in C entwicklet.* 

*Heute finden wir C noch immer in den Kerneln der Betriebssysteme Mac OS, Linux und Windows, in den mobilen Betriebssystemen Andriod, iOS und Windows Phone. Aber auch  Anwendungen wie MySQL oder dem Microsoft SQL Server sind in C (und C++) entwickelt.*

*C findet sich außerdem oft in eingebetteten Systemen (engl. embedded systems) wieder.* 

**Student:** *Aus welchem Grund wird hier überhaupt C genutzt? Wäre eine andere Sprache nicht viel einfacher?*

**Professor:** *C erlaubt die direkte Manipulation des Speichers. Also das Schreiben und Lesen aus beliebigen Speicheradressen. Noch besser, können an diese beliebigen Speicheradressen beliebige Werte geschrieben werden. Das erklärt, weshalb C in den oben genannten Software-Systemen Anwendung findet.* 

*Zugegeben, es gibt einige Einschränkungen, die es doch nicht so einfach machen überall quasi alles zu schreiben und zu lesen und das ganze birgt auch einige Gefahren. Aber gegenüber höheren Sprachen, die das Speichermanagement vor dem Entwickler überwiegend verbergen, lässt uns C direkt und ohne Umwege mit dem Speicher sprechen und ist für ein Betriebssystem (dessen Hauptaufgabe unter anderem die Kommunikation mit dem Speicher ist) mehr als geeignet.*

**Student:** *Aber warum nutzen wir in der Vorlesung überhaupt C? Warum soll ich jetzt plötzlich C lernen? Geht das nicht ganz ohne Programmieren? Andere Vorlesungen zum Thema Betriebssystem progammieren doch auch kein C!*

**Professor:** *Um die grundlegenden Konzepte, insbesondere im Umgang mit Speicher zu verdeutlichen, greifen wir nunmal in der Vorlesung Betriebssysem auf die Programmiersprache C zurück. Im Laufe der Verantaltung werden darüber hinaus einige Übungen mit Hardware druchgeführt. Auch hier ist es aus pragmatischen Gründen naheliegend mit der Hardware mit C zu sprechen. In anderen Vorlesungen wird auch kein Code auf einem ESP32 deployed...Außerden, Sie studieren Software Engineering, da sollte es Ihnen halbwegs Spaß machen etwas zu programmieren...*

**Student** *OK, aber warum soll ich das jetzt lernen? Ich werde das später in meinem Job doch eh nicht mehr brauchen..."*

**Professor:** *Ziel dieses Crashkurses ist es Sie in die Lage zu versetzen,  C-Programme lesen zu können und einfach C-Progammer selbst schreiben zu können. Sie werden in Ihrer Laufbahn immer wieder über C-Code stolpern. Und leider ist der nicht immer ganz so einfach zu lesen. Außerdem möchte ich Ihnen hier die Grundlagen an die Hand geben, dass sich weiteres Wissen im C-Umfeld eigenständig aneignen können, sich in eigene Bibliotheken einarbeiten können oder auch beurteilen zu können ob es in Ihrem ersten echten Projekt nach dem Abschluss geschickter ist C oder Rust zu nutzen. Wir nennen so etwas eine KOpetenz, die Sie im Studium lernen. Also mehr als nur das Auswendiglernen der Schlüsselworte von C.* 

**Student:** *OK, also wo fange ich da am besten an?*

## Grundlagen 
## Funktionen 
## Pointers 
## Datenstrukturen 
## C-Bibliotheken 
## Anhang 
## C Style Guide 