# C Crashkurs

---

Created: 2020/09/16 21:21:48  
Last modified: 2020/09/16 21:37:12  
Version: 0.0.1-beta  
Autor: [aheil](https://www.github.com/aheil)

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

**Professor:** *Ziel dieses Crashkurses ist es Sie in die Lage zu versetzen, C-Programme lesen zu können und einfache C-Progamme selbst schreiben zu können. Sie werden in Ihrer Laufbahn immer wieder über C-Code stolpern. Und leider ist der nicht immer ganz so einfach zu lesen. Außerdem möchte ich Ihnen hier die Grundlagen an die Hand geben, dass sie sich weiteres Wissen im C-Umfeld eigenständig aneignen, sich in eigene Bibliotheken einarbeiten oder auch beurteilen können, ob es in Ihrem ersten echten Projekt nach dem Abschluss geschickter ist C oder Rust zu nutzen. Wir nennen so etwas eine Kompetenz, die Sie im Studium lernen. Soetwas ist besser als nur das Auswendiglernen der Schlüsselworte von C.*
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

[GCC](https://gcc.gnu.org/) bzw. die GNU Compiler Collection ist eine Software-Sammlung die es Ihnen erlaubt unter anderem C-Code zu übersetzen. `gcc` ist hierbei der eigentliche C-Compiler, den wir nutzen.

### C-Programme schreiben

C Programme lassen sich recht einfach erstellen:

1. C-Code schreiben 
2. Compilieren und Linken 
3. Programm ausführen

### Übung 1: Hallo Welt 

#### 1. C-Code schreiben

Wie bei jeder Sprache starten wir mit einem einfachen *Hallo Welt* Programm.
Die einzelnen Besandteile des Codes betrachten wir später. Jetzt geht es zuerst darum, das Programm zum Laufen zu bringen.

```c
#include <stdio.h>

int main()
{
    printf("Hallo Welt\n");
}
```

**Übungsaufgabe:** 
 1. Was passiert, wenn Sie die Zeile `#include <stdio.h>` aus dem Programm entfernen und neu kompilieren. Was bedeutet dies?
 2. Warum ist der Rückgabewert der *main*-Funktion *int*? An wen übergibt diese Funktion den Wert und wo wird dieser zurück gegeben? 

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

Sie haben nun Ihr erstes C-Programm geschrieben, kompiliert und getartet und außerdem bereits einigies über die Linux Shell und C-Programmierung gelernt. Falls Sie nun die Frage quält, woher das Betriebssystem weiß, dass es beim Starten von *hallowelt* die *main*-Funktion aufrufen soll, werden Sie noch einigen Vorlesungseinheiten auf die Folter gespannt. Aber genau diesen Punkt werden werd noch im Laufe der Vorlesung kennen lernen.

## Funktionen

### Funktionen in a Nutshell

Funktionen kennt vermutlich jeder noch aus Mathemathik. Bei Funktion der Art 

(1) *y = g(f(x))*

könntnen die Funktionen *g(x)* und *f(x)* beispielsweise wie folgt aussehen: 

(2) *g : y = x +1* und *f : y = x \* 2* 

In C schreiben wir die Funktion aus (1) folgendermaßen:

```c
int x = 5;
int y = g(f(x));
    
printf("%d\n", y);
```

Wenn wir nun das ganze nochmals mit einer *main*-Funktion betrachten, würde der C-Code so aussehen: 

```c
int main(int argc, char* argv[])
{
    long x = (long) argv[1];
    long y = g(f(x));
    
    printf("%ld\n", y);
}
```

Und als Formel würden wir das so schreiben: 

(3) *y = main(g(f(x))*

Die Funktionen in C (oder allgemein in Programmiersprachen) funktionieren demnach mehr oder weniger wie Funktionen in der Mathemtik.

### Der Unterschied zwischen Funktionen, Methoden und Prozeduren

Die drei Begriffe Funktion, Prozedur und Methode werden oft unscharf bzw. als Synonym verwendet. Die Meinungen wie diese exakt definieren sind weichen hier durchaus voneinander ab. Grundsätzlich lassen sich die Begriffe wie folgt beschreiben:

* Eine Funktion hat einen Rückgabewert 
* Eine Prozedur hat keinen Rückgabewert
* Methoden werden Funktionen oder Prozeduren in der objektortientierten Programmierung genannt
* In manchen Programmiersprachen wird dann  zwischen *Methoden ohne Rückgabewerten* und *Methoden mit Rückgabewerten* unterschieden

Übungsaufgaben:
1. Ändern Sie den Rückgabewert der *main*-Funktion des *hallowelt* Programms in *void* und prüfen Sie, ob sich das Programm noch ausführen lässt. Was erkennen Sie? 
2. Lesen Sie den [Artikel von Bjarne Stroustrup](https://www.stroustrup.com/bs_faq2.html#void-main) bezüglich der Signatur der *main*-Funktion. Verinerlichen Sie dieses Wissen, Sie werden vermtutlich Ihre gesamte Karriere in Situationen kommen, in denen über die Signatru der *main*-Funktion in C diskutiert wird. 

### Funktionsprototyp

Betrachten wir unser Beispiel von zuvor. Die Reihenfolge der Funktionen ist hier nicht willkürlich gewählt. In C ist es erforderlich, dass Funktionen vor deren Verwendung definiert werden.

```c
#include <stdio.h>

long f(long x)
{
    long y = x * 2;
    return y;
} 

long g (long x)
{
    long y = x + 1;
    return y; 
}

int main(int argc, char* argv[])
{
    long x = (long) argv[1];
    long y = g(f(x));

    printf("%ld\n", y);
}
```

Übungsaufgaben:

1. Ändern Sie den Code aus dem vorherigen Beispiel so, dass die Implementierung der *main*-Funktion vor *g* und *f* steht. Kompilieren Sie das Programm. Was passiert?
2. Ändern Sie nochmals das ursprüngliche Prgramm. Löschen Sie dieses Mal die Zeile `#include <stdio.h>`. Kompilieren Sie das Program. Was beobachten Sie? Wie könnte das mit der vorherigen Aufgabe zusammenhängen?
3. Nehmen Sie nun nochmals das Programm aus der ersten Übungsaufgabe und ändern Sie es entsprechend dem untenstehenden Beispiel ab. Kompilieren Sie das Programm. Was beobachten Sie?

```c
#include <stdio.h>

long f(long x);
long g (long x);

int main(int argc, char* argv[])
{
    ...
}

long f(long x)
{
    ...
} 

long g (long x)
{
    ...
}
```


Übungsaufgaben:

1. Suchen Sie im Ordner */usr/include* nach der Datei *stdio.h*. Öffnen Sie die Datei und suchen hier nach *printf*. Keine Sorge Sie müssen nicht verstehen, was hier steht. 

*gcc* weiß, dass die Datei stdio.h im Pfad */usr/include* zu finden ist. Ebenso, wo die Standard C Bibliothek zu finden ist, in der die Funktionen letztendlich definiert sind. Diese liegen je nach System unter */usr/lib/libc*, */lib/libc*, */usr/lib/klibc* o.ä. Der Linker wird als zweiten Schritt ausgeführt, wenn Sie *gcc* aufrufen. Stark vereinfacht ausgedrückt kombiniert der Linker nach dem Kompilieren sämtliche Objektdateien (engl. object files) zu einem ausführbaren Programm und berechnet die Adressen von Code und Daten. Bisher waren alle Adressen sog. symbolische Adressen (engl. symbolic adresses). Da der Linker nun das "fertige" Programm kennt, weiß er auch an welcher Stelle später der ausführbare Programmcode als auch die Daten liegen und kann somit die numerischen Adressen (engl. numerical addresses) berechnen. Im Verlauf der Vorlesung greifen wir dies nochmal auf, wenn es darum geht, wie Prozesse ausgeführt werden und wie auf Daten im Speicher zugegriffen wird. 

## Pointers 

Dieser Kurs richtet sich insbesondere an unserer zweites Semester. In der Regel haben Sie noch nicht viel mit Pointern zu tun gehabt. Je nach dem wie Ihr späteres Berufsleben aussieht werden Sie es jedoch immer wieder mal, mehr oder weniger oft mit Pointer zu tun bekommen. JE näher Sie übrigens an Hardware arbeiten, desto stärker werden Sie Pointer verfolgen. Warum werden Sie im Verlauf der Vorlesung noch berstehen lernen.

Aber was sind eigentlich Pointer? 

Pointer sind, wie die Übersetzung vermuten lässt, Zeiger. Wenn Sie sich jetzt fragen, worauf diese Pointer zeigen, haben Sie schon einmal richtig mitgedacht. 

### C und Variablen 

Bevor wir uns mit Pointern beschäftigen, schauen wir uns etwas genauer an, was in C mit Variablen passiert. Dafür nehmen wir den folgenden Code. Dieser nutzt ausschließlich Sprachelemente, die wir bisher gelernt haben. Allerdings macht der Code auf den ersten Blick zugegebenerweise nichts sinvolles. 

```c
#include <stdio.h>

void foo();

int main()
{
    foo();
}

void foo()
{
    static int s;
    int n;

    printf("static s = %d\n", s++);
    printf("local  n = %d\n", n++);

    foo();
}
```

Übungsaufgaben:

1. Kompilieren Sie das Programm und starten Sie es. Brechen Sie das Programm mit der Tastenkombination <kbd>CTRL</kbd>+<kbd>C</kbd> ab. Was schließen Sie aus der Ausgabe? Scrollen Sie dafür auch zum Beginn der Ausgabe. Lassen Sie das Programm mehrfach laufen und wiederholen Sie Ihre Beobachtungen.

Je nach eingesetztem Betriebssystem sehen Sie hier unterschiedliche Ausgaben:

```bash
> static s = 0    
> local  n = 32709
> static s = 1    
> local  n = 32709
> static s = 2    
> local  n = 32767
> static s = 3    
> local  n = 0    
> static s = 4    
> local  n = 0    
> static s = 5    
> local  n = 32767
...
```

Auch wenn Ihnen das jetzt erst einmal komisch vorkommen solte, das Programm macht genau das, was es machen soll und verhält sich zwar indeterministisch aber erwartungkonform. 
Sollten Sie nicht wissen, was indeterministisch. Indeterminismus ist übrigens eines der schlimmsten Dinge, die uns Entwicklern passieren können und machen uns besonders beim Debuggen das Leben schwer. Wenn sich ein so kleines Programm wie oben bereits so verhältt, was ist dann wohl erst bei Programmen mit abertausenden von Zeilen Code?

Aber schauen wir uns nun Schritt für Schritt den Code an, der Ihnen vermutlich nun Kopfzerbrechen bereitet: 

Der Beginn ist trivial: Die *main*-Methode ruft zunächst eine Methode *foo* auf, die sich am Ende selbst wieder aufruft. Falls Sie es im Studium noch nicht gelernt haben, das ist *Rekursion*. 

In der *foo*-Methode wird zunächst mittels ```static int s;``` eine statische Variable *s* definiert.

Statische Variablen gibt es in Ihrem Programm genau einmal. Obwohl die Variable hier in einer Funktion definiert wird, die ettliche Mal aufgerufen wird, wird nur ein einziges Mal für die Variable Speicher allokiert. Wenn in der Zeil der Ausgabe nun die Variable mittels ```s++``` um eins erhöht wird, wird dieser Wert immer an der gleiche Adresse  gelesen und geschrieben. Daher wird der Wert von Aufruf zu Aufruf größer. 

Das die Variable bei 0 anfängt ist kein Zufall, ein Blick in den [C99 Standard](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf) liefert uns folgende Information:

> If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate. If an object that has static storage duration is not initialized explicitly, then:
> — if it has pointer type, it is initialized to a null pointer;
> **— if it has arithmetic type, it is initialized to (positive or unsigned) zero;**
> — if it is an aggregate, every member is initialized (recursively) according to these rules;
> — if it is a union, the first named member is initialized (recursively) according to these rules.

Die Variable *s* wird als arrithmetischer Typ also mit 0 initialisiert. 

Anders sieht es nun aber bei der Variable x aus, die mittels ```int x;``` deklariert wird. Vermutlich haben Sie den ersten Satz überlesen, daher schauen wir uns den nochmals genauer an. 

> **If an object that has automatic storage duration is not initialized explicitly, its value is indeterminate.**

Die Variable *x* wird auf dem sogenannten Stack gespeichert. Den Unterschied zwischen Stack und Heap lernen Sie noch im Verlauf der Vorlesung kennen. Wichtig ist jedoch, dass der Speicher für die Variable automatisch auf dem Stack reserviert wird. Und hier liegt der Hase im Pfeffer: Die Variable wird an der nächstbesten Stelle in dem Speicherbereich angelegt, der in unsererm Stack frei ist. Was auch immer in dem Speicher steht, wird nun beim lesenden Zugriff auf die Variable ausgelesen. Diese Idee behalten Sie einmal im Kopf, denn hier nähern wir uns gewissermaßen bereits dem Konzept von Pointern. 

Wenn Sie das Programm unter Windows laufen lassen, könnten Sie Glück haben und die Variable enthält immer den Wert 0. Dies liegt aber nicht an der C-Version unter Windows, sondern an der Tatsache, dass Windows ungenützte Speicherbereiche in seiner Freizeit löscht, indem Sie mit 0 überschrieben werden. Sie sollten aber keine Wette darauf abschließen, dass genau der Speicherbereich, der beim Aufruf der Funktion allokiert wird, bereits aufgeräumt wurde. 

### Pointer definieren und verwenden

Erinnern Sie sich noch an diese Sache mit dem Stack aus dem vorherigen Abschnitt? Versuchen wir einmal heruaszufinden wo im Speicher die Variablen *x* und *s* abgelegt sind. 

Und genau in diesem Moment benötigen wir Pointer. Die zeigen nämlich, und das haben Sie jetzt sicherlich schon vermutet, auf einen Speicherbereich. Pointer sind also nichts anderes als Variablen. Anders als arritmetische Variablen wie ein *Integer* enthält ein Pointer jedoch eine Adresse eines anderen Objektes.

Definiert werden Pointer wie folgt:

```c
Datentyp *Pointername 
```

Möchten wir also Pointer für unserer beiden Variablen definieren sieht dies folgermßen aus: 

```c
int *s_ptr;
int *n_ptr;
```

Das *int_* gibt dabei den Datentyp an, dessen Adresse wir wissen wollen, und nicht etwa den Datentyp des Pointers. Dieser richtet sich nach der Rechner-Architektur, also 8-, 16-, 32- oder 64-Bit.  Das Sternchen vor dem Variablennamen heißt übrigens *Reference-* oder *Indirection-Operator*. 

Um nun an die Adresse einer Variable zu gelangen greift man auf die Variable mittes des *Address-Operators* zu:

```c
&Variablenname
```

und weist dies einem Pointer zu. In unsererm Beispiel sieht das dann letztendlich so aus:

```c
s_ptr = &s;
n_ptr = &n;
```

Alles zusammen können wiur unser Programm nun etwas umschreiben: 

```c
void foo()
{
    static int s;
    int n;

    int *s_ptr;
    int *n_ptr;

    s_ptr = &s;
    n_ptr = &n;

    printf("static s = %d, address =%p\n", s++, s_ptr);
    printf("local  n = %d, address =%p\n", n++, n_ptr);

    foo();
}
```


Übungsaufgabe:

1. Ändern Sie Ihr Programm aus der vorherigen Übung ab, kompilieren Sie es und lassen Sie es laufen. Studieren Sie die Ausgabe. Sind die bisherigen Annahmen hierdurch bestätigt? 


```bash
static s = 0, address = 0x7f6c15b4e014
local  n = 32620, address = 0x7fffc1085364
static s = 1, address = 0x7f6c15b4e014
local  n = 0, address = 0x7fffc1085334
static s = 2, address = 0x7f6c15b4e014
local  n = 0, address = 0x7fffc1085304
static s = 3, address = 0x7f6c15b4e014
local  n = 0, address = 0x7fffc10852d4
static s = 4, address = 0x7f6c15b4e014
local  n = 32767, address = 0x7fffc10852a4
static s = 5, address = 0x7f6c15b4e014
local  n = 32767, address = 0x7fffc1085274
```

Wie wir sehen, liegt die statische Variable *s* immer an der Adresse ```0x7f6c15b4e014```, woggen *x* bei jedem Aufruf an einer neuen Adresse liegt. Das macht auch Sinn, da - obwohl die Variable für uns immer den gleichen Namen hat - diese immer nur in der jeweiligen Funktion gültigkeit hat. Soblad wir aus einer aufgerufenen Funktion wieder zurückkehren würden, würden wir auch wieder auf die voirher genutzt Variable zugreifen können.  


### Exkurs: Auf der Suche nach den verlorenen 16 Bit.

Die Adressen werdne hier als Headezimal-Werte ausgegeben. 

Nehmen wir die Adresse, an der sich die statische Variable *s* befindet, ```0x7f6c15b4e014``` und rechnen diese um in Bit kommen wir auf den Wert ```0111 1111 0110 1100 0001 0101 1011 0100 1110 0000 0001 0100```. Wer nun zählt, findet hier *nur* 48 Bit. Das sind weder 32 noch 64, wie man vermuten möchte.  Im vorliegenden Fall wurde das tatsächlich auf einem 64-Bit Windows System ausgeführt. Allerdings werden bei gängigen 64-Bit CPUs nur 48 der theoretischen 64 Bit zur Addressierung eines Addressraums eines Prozesses genutzt. Konkret bedeutet dies, dass der Adressraum eines Prozesses kleiner ist, als er sein könnte. Was das genau bedeutet lernen Sie im Verlauf der Vorlesung noch genauer kennen, wenn wir uns mit Prozessen und Adressräumen befassen.

### One More Thing 

Jetzt da geklärt ist, wo die vermissten Bits sind, und wie wir an die Adresse kommen, stellt sich Ihnen vielleicht noch die Frage, was passiert eigentlich, wenn der Reference-Operator auf einen Pointer angewandt wird!? 

```c#
*x_ptr = x;
```

Sofern *x_ptr* ein Pointer ist, liefert `*x_ptr`* mit dem Inhalt an der Adresse. Somit lässt ich mittels ```px = x;``` der Inhalt der Variable *X* an die Adresse schreiben, die in x_ptr gespcihert ist. Eingeitnlich einfac, oder?

Zum NAchvollziehen, das folgende Beispiel, in dem wir einige Variableninhalten kopieren. 

```c
int main()
{
   int x;
   int *x_ptr;
   
    x = 5;
    x_ptr = &x;

    printf("x = %d\n", x);
    printf("&x_ptr = %p\n", x_ptr);

    int y;
    int *y_ptr;

    y = 6;
    y_ptr = &y;
    *x_ptr = y;

    printf("x = %d\n", *x_ptr);
    printf("&x_ptr = %p\n", x_ptr);

    *y_ptr = 7;

    printf("y = %d\n", *y_ptr);
    printf("&y_ptr = %p\n", y_ptr);
}
```

Übungsaufgabe:

1. Kompilierenu und führen Sie das obige Programm aus. Spielen Sie etwas mit den Zuweisungen zwischen Variablen und Pointern herum, um ein Gefühl dafür zu entwickeln, wie sich das Programm verhält. 

An der Stelle sei erwähnt, dass Sie die Übungsaufgaben natürlich nur lesen können und den damit verbundenen *Arbeitsauftrag* ignorieren können. Aber Sie werden Programmieren nur durch Programmieren lernen. Nicht durch lesen, wie man programmiert. Wenn Sie dem vorherigen Hinweis nachgekommen sind, sollten Sie folgende Ausgabe auf dem Bildschirm sehen.

```bash
> x = 5
> &x_ptr = 0x7fffe6a99500
> x = 6
> &x_ptr = 0x7fffe6a99500
> y = 7
> &y_ptr = 0x7fffe6a99504
```
### C isn't hard

Früher oder später werden Sie über komplexere Ausdrücke mit POintern stolpern. Und vermutlich auch übver folgendes Meme:

> *void (*(*f[])())()* defines *f* as an 
> array of unspecified size, of pointers to
> functions that return pointers to functions that
> return *void*.

Verzweifeln Sie nicht, und - viel wichtiger - ignorieren sie den Ausdruck nicht. Es gibt zahlreiche Anleitungen wie sie [komplexe Popinter-Anweisungen entschlüsseln](https://www.codementor.io/@dankhan/how-to-easily-decipher-complex-pointer-declarations-cpp-so24b66me). Üben Sie strukturiert vorzugehen und versuchen Sie den Ausdruck Stück für Stück zu verstehen.

Für die Beispiel, Aufgaben und Übungen in der Vorlesung werden Ihnen die obigen Anweisungen ausreichen. Der Rest kommt durch Übung. 

## Datenstrukturen 
## C-Bibliotheken 
## Anhang 
## C Style Guide 

---

![https://creativecommons.org/licenses/by/4.0/](https://i.creativecommons.org/l/by/4.0/88x31.png "Creative Commons License")  
This work is licensed under a [Creative Commons Attribution 4.0 International License](https://creativecommons.org/licenses/by/4.0/).
