---
# Front matter
lang: ru-RU
title: "Отчёт по лабораторной работе №1"
subtitle: "Развертывание виртуальной машины"
author: "Жижченко Валерия Викторовна НФИбд-03-18"

# Formatting
toc-title: "Содержание"
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
fontsize: 12pt
linestretch: 1.5
papersize: a4paper
documentclass: scrreprt
polyglossia-lang: russian
polyglossia-otherlangs: english
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase
indent: true
pdf-engine: lualatex
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Приобретение практических навыков установки операционной системы на виртуальную машину, размещение файлов на сервисе Git и подготовка отчета в формате Markdown.

# Выполнение лабораторной работы

Называю виртуальную машину

![Называю машину](../image/01.png){ #fig:001 width=70% }

Указываю объем памяти.

![Указываю объем](../image/02.png){ #fig:002 width=70% }

Создаю новый виртуальный жесткий диск

![Жесткий диск](../image/03.png){ #fig:003 width=70% }

Указываю тип файла 

![Тип файла](../image/04.png){ #fig:004 width=70% }

Указываю формат хранения 

![Динамический виртуальный ЖД](../image/05.png){ #fig:005 width=70% }

Укаываю размер файла 

![20 ГБ ](../image/06.png){ #fig:006 width=70% }

Добавляю новый привод оптических дисков и выбраю образ

![DVD](../image/07.png){ #fig:007 width=70% }

Запускаю виртуальную машину.

![Приветственный экран](../image/08.png){ #fig:008 width=70% }

Выбираю язык.

![Установка языка](../image/09.png){ #fig:009 width=70% }

Указываю параметры установки

![Настройка клавиатуры](../image/10.png){ #fig:010 width=70% }

![Настройка часового пояса](../image/11.png){ #fig:011 width=70% }

![Выбор программ](../image/12.png){ #fig:012 width=70% }

![KDUMP](../image/13.png){ #fig:013 width=70% }

![Настройка сети и имени узла](../image/14.png){ #fig:014 width=70% }
 
![Создаю пароль root](../image/15.png){ #fig:015 width=70% }

![Создаю пользователя](../image/16.png){ #fig:016 width=70% }

![Установка](../image/17.png){ #fig:017 width=70% }

![Лицензионное соглашение](../image/18.png){ #fig:018 width=70% }

![Вхожу под своим поьзователем](../image/19.png){ #fig:019 width=70% }

![Установка драйверов](../image/20.png){ #fig:020 width=70% }

![Перезагрузка](../image/21.png){ #fig:021 width=70% }

# Вывод

Я приобрела навыкустановки операционной системы на виртуальную машину, разместила файлы работы на сервисе Git и подготовила отчет в формате Markdown.