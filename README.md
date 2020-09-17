# C Crashkurs

---

Created: 2020/09/16 21:21:48  
Last modified: 2020/09/16 21:37:12  
Version: 0.0.0-beta  
Autor: @aheil

---

Crashkurs zur Vorlesung Betriebssystem an der Hochschule Heilbronn im Studiengang  Software Engineering Bachelor (SEB). 

Inhalt 
* [Dialog](#Dialog)
* [Grundlagen](#grundlagen)
* [Funktionen](#funktionen)
* [Pointers](#pointers)
* [Datenstrukturen](#datenstrukturen)
* [C-Bibliotheken](#bibliotheken) 
* [Anhang 1: C Style Guide](#c-style-guide)
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

**Professor:** *Ziel dieses Crashkurses ist es Sie in die Lage zu versetzen,  C-Programme lesen zu können und einfach C-Progammer selbst schreiben zu können. Sie werden in Ihrer Laufbahn immer wieder über C-Code stolpern. Und leider ist der nicht immer ganz so einfach zu lesen. Außerdem möchte ich Ihnen hier die Grundlagen an die Hand geben, dass sich weiteres Wissen im C-Umfeld eigenständig aneignen können, sich in eigene Bibliotheken einarbeiten können oder auch beurteilen zu können ob es in Ihrem ersten echten Projekt nach dem Abschluss geschickter ist C oder Rust zu nutzen. Wir nennen so etwas eine Kompetenz, die Sie im Studium lernen. Soetwas ist besser als nur das Auswendiglernen der Schlüsselworte von C.* 

**Student:** *OK, also wo fange ich da am besten an?*

## Grundlagen 

### Voraussetzungen

Für die meisten Übungen insbesonere die C-Übungen benötigen Sie ein Linux System. Folgende Optionen können Sie hierfür gleichermaßen nutzen: 

* Sie verwenden bereits Linux (Ubuntu, Debian etc.) ✅
* Sie verwenden MacOS ✅
* Sie verwenden [Windows 10 mit Windows Subsystem for Linux (WSL)](https://docs.microsoft.com/en-us/windows/wsl/install-win10) ✅
* Frühere Windows Version ❌

Testen ob `gcc` installiert ist. 

```shell
> gcc
> gcc: fatal error: no input files
> compilation terminated.
```

[GCC](https://gcc.gnu.org/) bzw. die GNU Compiler Colleciton ist eine Software-Sammlung die es Ihnen erlaubt unter anderem C-Code zu übersetzen. `gcc` ist hierbei der eigentliche C-Compiler, den wir nutzen.

### C-Programme schreiben

C Programme lassen sich recht einfach erstellen:

1. C-Code schreiben 
2. Compilieren und Linken 
3. Programm ausführen

### Übung 1: Hallo Welt 

#### 1. C-Code schreiben

Wie bei jeder Sprache starten wir mit einem einfach *Hallo Welt* Program.
Die einzelnen Besandteile des Codes betrachten wir später. Jetzt geht es erstinmal darum, das Programm zum Laufen zu bringen.

```c
#include <stdio.h>

int main()
{
    printf("Hallo Welt\n");
}
```

**Übungsaufgabe:** 
 1. Was passiert, wenn Sie die Zeile `#include <stdio.h>` aus dem Programm entfernen und neu kompilieren. Was bedeutet dies?
 2. Warum ist der Rückgabewert der *main*-Methode *int*? An wen übergibt diese Methode den Wert und wo wird dieser zurück gegeben? 

#### 2. Compililieren und Linken

Führen Sie folgenden Befehl auf der Kommandozeile/Shell aus:

```bash
> gcc hallowelt.c
```

Werfen Sie einen Blick in das Verzeichnis in dem sich Ihr C-Code befindet. *gcc* hat eine Datei `a.out` erstellt. 

**Übungsaufgaben:** 
1. Wie müssen Sie *gcc* aufrufen, dass Ihr Programm zum ausführen *hallowelt* heißt? 
2. Führen Sie *gcc* entsprechend aus um eine Datei Namens *hallowelt* zu erzeugen.

#### 3. Programm ausführen

Starten Sie das Program mit `./hallowelt` und freuen Sie sich über den Erfolg. 

```bash
> ./hallowelt
> Hallo Welt
```

Führen Sie nun folgenden Befehl aus: `./hallowelt && echo "0" || echo "1"`

Sie sollten nun folgendes auf Ihrem Bildschirm sehen: 

```bash
> ./hallowelt && echo "0" || echo "1"
> Hallo Welt
> 0
```

Zugegben, hier geschieht einiges an "Magic". Zusammengefasst werted dieser Ausdruck den Exit Code des Programms *hallowelt* aus und auf der Schell eine 0 aus, wenn der Exit Code 0 bzw. eine 1, wenn der Exit Code 1 ist. Hierbei handetl es sich um ein besonderes Konstrukt, sogenannter List Constructs, die Sie in Skripten nutzen können. 

Wenn Sie einfach nur den vorherigen Exit Codes sehen wollen nutzen Sie `$?` entwender auf der Konsol oder in einem SKript. 

```bash
> ./hallowelt
> Hallo Welt
> echo $?
> 0
```

**Übungsaufgaben**
1. Führend Sie das Programm *hallowelt* einmal ohne vorgestelltes *./* aus. Sie erhalten (vermutlich) einen Fehler. An was könnte das liegen. Lesen Sie [diesen Artikel](https://linuxundich.de/gnu-linux/uber-die-verwendung-von-in-shell-befehlen/) um das Gehemnis zu lüften.
2. Lesen Sie [diesen Artikel](https://tldp.org/LDP/abs/html/list-cons.html) um die Funktionsweise von List Constructs 
2. Schreiben Sie nun zwei C-Programme. Das erste Program gibt *Hallo* aus, das Zweite *Welt*. Das erste Programm liefert als Exit-Code nach erfolgreicher Ausgabe den Code 0. Schreiben Sie nun ein Bash-Script, das zunächst das erste Programm aufruft und danach Programm zwei aufruft. Allerdings nur, wenn des Exit Code des ersten Programms der Code 1 ist. Im anderen Fall gebene Sie einfach das Wort *Error* aus - und zwar ohne Ihre C-Programme abzuändern. 

Sie haben nun Ihr erstes C-Programm geschrieben, kompiliert und getartet und außerdem bereits einigies über die Linux Shell und C-Programmierung gelernt. Falls Sie nun die Frage quält, woher das Betriebssystem weiß, dass es beim Starten von *hallowelt* die *main*-Methode aufrufen soll, werden Sie noch einigen Vorlesungseinheiten auf die Folter gespannt. Aber genau diesen Punkt werden werd noch im Laufe der Vorlesung kennen lernen.


## Funktionen 
## Pointers 
## Datenstrukturen 
## C-Bibliotheken 
## Anhang 
## C Style Guide 

---

![http://creativecommons.org/licenses/by/4.0/](https://i.creativecommons.org/l/by/4.0/88x31.png "Creative Commons License")  
This work is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).