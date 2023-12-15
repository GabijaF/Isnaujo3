# isnaujo
nd
## 1 strategija
Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvociu". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba galvociu).

Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu:

### vector atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![v1](https://github.com/GabijaF/isnaujo/assets/145053488/d277058c-118b-4818-876c-8f94c95f281f)

### list atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![l1](https://github.com/GabijaF/isnaujo/assets/145053488/0db2feba-5eae-410b-9172-1860910a5072)


programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

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
