# isnaujo
nd

https://github.com/GabijaF/isnaujo/tree/v0.1?tab=readme-ov-file#isnaujo

## 1 strategija
Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvociu". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba galvociu).

Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu:

### vector atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![v1](https://github.com/GabijaF/isnaujo/assets/145053488/d277058c-118b-4818-876c-8f94c95f281f)

### list atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![l1](https://github.com/GabijaF/isnaujo/assets/145053488/0db2feba-5eae-410b-9172-1860910a5072)


Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0030413| 0.0040084 |  0.0030096| 0 |
| 10000  | 0.0780444 | 0.0080004 |0.0356217 |0.0462288|
| 100000 | 1.57536 | 0.138789 | 0.16402 | 0.239093 |
| 1000000 | 3.93834 | 0.492667 | 0.71094| 1.02808|
| 10000000 | 33.473  | 7.35889 |  8.27889 |9.24557  | 

### list:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |   0.0040745 |0.0039971  | 0.0039847| 0.0040013 |
| 10000  |0.129829 |  0.0119939  |0.016233 |0.0199896|
| 100000 | 1.58593 | 0.126619 |  0.162997  |0.226659 |
| 1000000 | 4.17133 | 0.49107 | 0.831084|  1.16655 |
| 10000000 | 71.1717  | 9.39051 | 16.5541 |23.466  | 

### Išvada: 
naudojant 1 strategija vector tipas veikia greičiau už list.
***
## 2 strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik galvociai. 

Atminties atveju si strategija efektyvesne, tačiau dažni trynimai gali būti "skausmingi", vector tipo konteineriams.

### vector atveju:
pateikta atmintis paleidus kodą su 100 000 studentų turinčiu failu:

![image](https://github.com/GabijaF/isnaujo/assets/145053488/15dd976e-c8d4-41a3-997c-1d194448d0f9)

### list atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0055643| 0.0302857  |   0.001001| 0.0015278 |
| 10000  | 0.0736229 |2.034884 |0.0095045 |0.0064997 |
| 100000 | 0.697874 | 221.699 |  0.0922078 |0.0691245 |

### list:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0038108| 0.0025442  | 0.0150123| 0.0360239 |
| 10000  | 0.101188 |0.01624 | 0.0095302  |0.0164752  |
| 100000 | 2.36938 | 0.380681 |  0.184752 |0.271983|
| 1000000  |  4.79024| 0.728885 | 0.792867| 1.06198 |
| 10000000  | 37.775 |7.8761  |8.46732 |10.7526  |

### Išvada: 
naudojant 2 strategija list tipas veikia greičiau už vector.
***
## 3 strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant greičiausiai veikiancia 1 strategiją, įtraukiant į ją "efektyvius" darbo su konteineriais metodus (naudosime copy_if, remove_copy_if, stable_partition).

Visus 3 algoritmus pritaikysim vector tipui, ir issirinksime greiciausiai veikianti, kuri pritaikysim ir list tipui.

Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector copy_if:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |   0.0060114 | 0.0010008  | 0.0020004| 0 |
| 10000  |0.0560198  |0.0080422 | 0.0069968  |0.0100863  |
| 100000 | 0.673109  | 0.0806257 | 0.0662875 |0.0910801|
| 1000000  | 3.63352| 0.566676 | 0.588548| 0.883478 |
| 10000000  | 29.162 |5.5803 |6.39421 |8.1343  |

### vector remove_copy_if:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0030174  |0.0049813  | 0.0019977 | 0.0010005  |
| 10000  |0.0645132   |0.0090003 | 0.0059997  |0.0099959  |
| 100000 | 0.671475   | 0.0806397 |0.0655182 |0.0826068|
| 1000000  |  3.62926 | 0.581576  | 0.600415| 0.864768|
| 10000000  | 28.8801  |5.61558 |6.407  |8.09974  |

### vector stable_partition:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0050357   |0.0010046  | 0.0020014 | 0.0010036  |
| 10000  |0.06951   |0.007  |0.0069991 |0.0110247 |
| 100000 | 0.687185    | 0.0715817 |0.0656571 |0.0936633|
| 1000000  |  3.65286| 0.554817  | 0.612013 | 0.869332|
| 10000000  | 28.9634   |5.60472 |6.38962   |8.08078  |

pastebime, kad stable_partition veikia greiciausiai todel ji pritaikysime ir list tipui:

### list stable_partition:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0030001  |0.0010006  | 0.0020002 | 0.0009913  |
| 10000  |0.0945954  |0.0255504 |0.0069999 |0.0110295 |
| 100000 | 1.11831  | 0.330492 |0.0740337 | 0.104791|
| 1000000  | 4.37306| 1.49957  | 0.622037 |  0.927994|
| 10000000  | 34.2783   |36.5723 |16.304  |11.792 |

### isvada:
Programos efektyvumas stipriai gali priklausyti ne tik nuo naudojamo konteinerio tipo, tačiau ir nuo naudojamų algoritmų.
***
