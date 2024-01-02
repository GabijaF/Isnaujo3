# isnaujo
nd

# Paleidimas
1. Parsisiunčiame [visas](https://github.com/GabijaF/isnaujo/tree/f9d4ac6c593da81b30665539baefc57d98618c1b/visas) aplanka is v1.0.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/df9c5f34-da87-4d06-a8a4-a080da43b587)
2.  Paleidžiame PowerShell
![image](https://github.com/GabijaF/isnaujo/assets/145053488/c2988d91-7b9e-44fb-a3d4-abd08fb10937)
3. Ir jame parašome RUNMME.bat paeiliui esantį tekstą.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/6f47ae50-46c9-42d7-a4cf-410b9109bebe)
![image](https://github.com/GabijaF/isnaujo/assets/145053488/f6bb0220-dd43-4240-939e-12ec0f664069)
4. Mūsų failas 'visas' prisipildė aplankais kurie reikalingi programos paleidimui. Atidarome Debug aplanka ir paleidžiame programa.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/9ffd81a8-81d2-44fe-8234-5a7af39509cc)
![image](https://github.com/GabijaF/isnaujo/assets/145053488/d503ed03-22ad-420f-895c-a5d2c0d94efb)
5. Programai baigusji užsidaro.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/39e93764-7253-44f3-b6aa-a6a9824e76c6)

# v.pradine
v.pradinė. generuoja.cpp paleidus koda klausia studento vardo ir pavardes. Poto klausia ar nd pazymius ir egzamino nori ivesti pats ar juos sugeneruoti atsitiktinai. parasius visu studentu duomenis programa paklausia koki galutini rezultata nori matyti vartotojas ar pagal vidurki ar mediana.

# v0.1
v0.1. tas pats kodas i .h ir .cpp failus ir panaudotas minimalus išimčių valdymas.

# v0.2

kodas nuskaito faila, ir isveda 2 failus: surusiuotus vargsiukai ir galvociai.

![image](https://github.com/GabijaF/isnaujo/assets/145053488/71e70385-afad-44e5-9b22-8174f87a9419)


1bandymas: 0.011086 sekundes
2bandymas: 0.0149357 sekundes
3bandymas: 0.0089862 sekundes
bandymu vidurkis: 0.0116693 sekundes



![image](https://github.com/GabijaF/isnaujo/assets/145053488/ad588561-0792-405e-a3af-2c569d4e61ba)


1bandymas: 0.1624448 sekundes
2bandymas: 0.1600233 sekundes
3bandymas: 0.1597411 sekundes
bandymu vidurkis: 0.1607364 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/ac835221-9415-4c34-b6a1-b666c9549161)


1bandymas: 1.3445191 sekundes
2bandymas: 1.3602037 sekundes
3bandymas: 1.3804005 sekundes
bandymu vidurkis: 1.36170776667 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/39f4934e-6867-4ab7-9d78-3c916f9dbc69)


1bandymas: 8.52987 sekundes
2bandymas: 9.06612 sekundes
3bandymas: 8.902099 sekundes
bandymu vidurkis: 8.83269633333 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/3cc7bb5e-87a2-4114-adeb-8250b544bf12)


1bandymas: 86.90333 sekundes
2bandymas: 165.64522 sekundes
3bandymas: 163.65959 sekundes
bandymu vidurkis: 138.736046667 sekundes

# v0.3
## Parametrai
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz;
RAM: 8GB 2667Hz
SSD: Micron_1100 240GB
****
****

### Ištirti:
ar pasikeistų ir kaip pasikeistų programos sparta, jei vietoje std::vector<Studentai> naudotumėte std::list<Studentai>.

Kadangi tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl šioje užduotyje matuosim:

* studentų rūšiavimą į dvi grupes;
* duomenų įrašymas į failus;

Matuosime kiekviena konteinerį su 5 skirtingais failais po 3 kartus pagal vidurkį ir pateiksime vidurkius.
****
****

## std::vector

![image](https://github.com/GabijaF/isnaujo/assets/145053488/ae041291-22f2-4c57-aadf-743f88352f88)

Studentų rūšiavimą į dvi grupes: 0.001335233336 sekundes <br>
Grupiu įrašymas į failus: 0.0063387 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/5f0e53a0-27b0-4cd8-b0e8-5794c7469ba0)

Studentų rūšiavimą į dvi grupes: 0.0418005 sekundes <br>
Grupiu įrašymas į failus: 0.03963506666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/34585652-e1bb-4ff7-82a8-5b7303aa7f48)

Studentų rūšiavimą į dvi grupes: 0.40813933333 sekundes <br>
Grupiu įrašymas į failus: 0.43132166666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/1cf892c4-9062-4726-a8ce-4ad40e2e6ef8)

Studentų rūšiavimą į dvi grupes: 3.96838666667 sekundes <br>
Grupiu įrašymas į failus: 4.11383333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/58a82b59-2c45-4f4d-b383-cdba6638bcb9)


Studentų rūšiavimą į dvi grupes: 41.8671333333 sekundes <br>
Grupiu įrašymas į failus: 42.7793666667 sekundes
****


## std::list

![image](https://github.com/GabijaF/isnaujo/assets/145053488/813bdc28-7693-426a-a244-991b3128ed27)

Studentų rūšiavimą į dvi grupes: 0.0051837 sekundes <br>
Grupiu įrašymas į failus: 0.00904976666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/c3da2164-c7ab-4678-b445-a332b6fd8dac)

Studentų rūšiavimą į dvi grupes: 0.0426777 sekundes <br>
Grupiu įrašymas į failus: 0.0399025 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/f197c1d4-3e1e-4ccd-9ebe-a56f9eba0c62)

Studentų rūšiavimą į dvi grupes: 0.41334333333 sekundes <br>
Grupiu įrašymas į failus: 0.42941333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/df332625-d459-43ed-a05a-f0e233be216f)

Studentų rūšiavimą į dvi grupes: 4.02931666667 sekundes <br>
Grupiu įrašymas į failus: 4.18043333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/f3f24168-310f-4e58-a2e2-4043458e36c0)

Studentų rūšiavimą į dvi grupes: 42.0294333333 sekundes <br>
Grupiu įrašymas į failus: 42.9918 sekundes
****
****

# Palyginimas

| Studentu sk.  | Rusiavimas(v) | Rusiavimas(l)|
| ------------- | ------------- | ------------- |
| 1000  | 0.001335233336 | 0.0051837 |
| 10000  | 0.0418005  | 0.0426777 |
| 100000 | 0.40813933333 | 0.41334333333 |
| 1000000 | 3.96838666667 | 4.02931666667 |
| 10000000 | 41.8671333333 | 42.0294333333 |


| Studentu sk.  | Dalijimas i 2gr(v) | Dalijimas i gr(l)|
| ------------- | ------------- | ------------- |
| 1000  | 0.0063387 | 0.00904976666 |
| 10000  | 0.03963506666  | 0.0399025 |
| 100000 | 0.43132166666 | 0.42941333333 |
| 1000000 | 4.11383333333 | 4.18043333333 |
| 10000000 | 42.7793666667 | 42.9918 |

Naudojant std::List vietoj std::Vector sparta, musu atvėju, keičiasi tik dalijant i 2gr(Pvz. 100000 atvėju). Tada List veikia greiciau nei Vector. Tačiau skirtumas tarp šių konteineriu neryškus.

# v0.1 
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
# v1.1
# Struct ir Class spartos palyginimas
Naudosime vector konteineri ir 3 strategija su 100000 ir 1000000 dydžio failais.

### Struct
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 7.64354 |0.239052 |0.233421 |  0.323678| 8.43969 |
| 1000000  |37.6255 | 2.5176 |  2.30584 |  3.52596| 45.9749|

### Class
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 9.25791  |0.3049 |0.313247 |  0.444165 | 10.3202 |
| 1000000  |42.1379|  2.70434|  3.02984 | 4.42701| 52.2991 |

Struct veikia siek tiek greiciau.
***
# Struct ir Class naudojant flag'us: O1, O2, O3.

##  flag O1

### Struct
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/2140f4ea-efd1-4b10-b3e6-93011241d15d)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 |5.86696  |0.149949 |0.217715 |  0.301116 | 6.53574| 
| 1000000  |28.0397|  1.5847 |   2.17208 |  3.39502 | 35.1915|

### Class
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/8b25c30e-e84f-4ad0-b6d0-1912c34a40d9)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 6.39531  |0.162314 |0.262658 | 0.35967 | 7.17995|
| 1000000  | 31.9339|  1.80929|  2.61274 | 3.75058| 40.1065|

##  flag O2

### Struct
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/f552060e-d082-43a7-af18-3558377a0f73)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 6.09648   |0.148169 |0.221382 | 0.310679   | 6.77671  | 
| 1000000  |28.7685|  1.59443 |   2.21691  | 3.22639| 35.8062 |

### Class
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/52390cac-dce2-4e30-9d3b-fd17d76638a6)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 6.96653 |0.174064 |0.252019  |  0.356397|7.74901 |
| 1000000  |31.0997| 1.57275 |   2.56937|3.70349|38.9453|

##  flag O3

### Struct
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/11a078e4-5d5b-4c3d-9899-db2a0f81a37a)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 6.30644   |0.147227 |0.21456  | 0.300797 |6.96903| 
| 1000000  |28.4045|  1.58906 |  2.17353  | 3.22658 |35.3936  |

### Class
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/4b84996b-e749-489e-9399-8823fa9e58e0)
 Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius| Is viso|
| ------------- | ------------- | ------------- |-----------------|--------------------|--------------------|
| 100000 | 6.63598  |0.168135  |0.271082| 0.371862| 7.44706|
| 1000000  |31.5163| 1.64145 | 2.58852 | 3.69087| 39.4371 |

Flagai paspartina tiek struct tiek class.

# v1.2
# Trijų metodų taisyklę
Triju metodu taisyklei, reikia:
*  Destructor
* Copy constructor
* Copy assignment operator


#### Ju realizacija mano kode:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/26c22e2c-c7ec-43c1-99d9-dd7368ddac47)

#### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/0b7009dc-6170-49c9-83f3-c7295a28ac6c)

#### rezultatai:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/8c985f95-13c5-493d-8ae5-69ad2188e000)
***
# perdengti įvesties ir išvesties metodai 
## duomenų įvestis
### rankiniu būdu
##### Paskirtis: 
Leidžia rankiniu būdu įvesti studento duomenis(varda, pavarde, nd, egz).
##### Naudojimas: 
Nuskaito duomenis iš standartinio įvesties srauto (is), įskaitant studento vardą, pavardę ir pažymius.
###### Funkcija:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/40c81eda-d527-46d5-a34c-e73d7e445f65)
###### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/1478d11b-69ad-44f9-8652-cfc1742661d4)

### automatiniu budu
#### Paskirtis: 
Automatiškai generuoja studentų duomenis.
#### Naudojimas: 
Sugeneruoja atsitiktinius vardus, pavardes ir nd, egz nurodytam studentų skaičiui (studentuSkaicius). Sugeneruoti duomenys yra išsaugomi į rezultatų failą (outFile).
###### Funkcija:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/24cc6f65-d123-4c7b-8381-0157d846d82f)
###### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/bd8830ce-98a9-4b5f-a86c-9204f921388e)

### iš failo
#### Paskirtis: 
Skaito studentų duomenis iš failo.
#### Naudojimas: 
Atidaro failą nurodytu pavadinimu (failoPavadinimas) ir nuskaito jame esančius duomenis. Skaito vardą, pavardę ir nd, egz.
###### Funkcija:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/a56547ba-53d5-49cb-9936-9c5c00e551b8)
###### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/48b3bf6a-dd51-4145-888f-d7d7f15123b1)


## duomenu išvestis
### į ekraną
#### Paskirtis:
Rodo studentų informaciją terminale.
#### Naudojimas: 
Atspausdina lentelę su studentų vardais, pavardėmis ir galutiniu balu.
###### Funkcija:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/1baa15ca-9dc2-4c57-93b5-5b072b8fbf28)
###### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/5e986ff9-1d89-4d84-9896-205492727ea6)

### į failą
#### Paskirtis: 
Rašo studentų informaciją į failą.
#### Naudojimas: 
Sukuria failą su nurodytu pavadinimu filename ir įrašo studentų duomenis.
###### Funkcija:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/51e83cd3-a39b-4fef-8a57-641fb3e496c5)
###### pvz:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/0aa3b5b7-1526-49f9-8f16-868557124692)

# v1.5
## Realizuota abstrakti klasė Žmogus, jos objektų kūrimas negalimas.
#### [1.5/zmogus.h](https://github.com/GabijaF/Isnaujo2/blob/5e8cf113aa636ddfd7303e0687be20146b5db7fc/1.5/zmogus.h) :
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/99e4c7c1-9f7d-4890-8b01-b30cfb37f4de)
#### bandymas:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/d55baced-af33-4242-bbcc-9f64b8d60688)
#### rezultatas:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/ecbc6f4c-4f03-4e9b-b213-ce56ee4b9344)
***
## Studento klasė išvestinė (derived) iš Žmogaus ir palaiko 1.2 versijoje realizuotą trejų metodų taisyklę. 
#### bandymas:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/4d5d358e-3543-44eb-a14b-4f7d06651494)
#### rezultatas:
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/c2642984-3c57-4ef9-9d18-fd72bcd3c5de)

# v2.0
Doxygen. 
![image](https://github.com/GabijaF/Isnaujo2/assets/145053488/44422f89-0087-4455-9180-c52d07f419e5)

