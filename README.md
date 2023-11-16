# isnaujo
nd
# Parametrai
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz;
RAM: 8GB 2667Hz
SSD: Micron_1100 240GB
****

###Ištirti: ar pasikeistų ir kaip pasikeistų programos sparta, jei vietoje std::vector<Studentai> naudotumėte std::list<Studentai>.

Kadangi tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl šioje užduotyje matuosim:

* studentų rūšiavimą į dvi grupes;
* duomenų įrašymas į failus;

Matuosime kiekviena konteinerį su 5 skirtingais failais po 3 kartus pagal vidurkį ir pateiksime vidurkius.
****

##std::vector

![282304717-71e70385-afad-44e5-9b22-8174f87a9419](https://github.com/GabijaF/isnaujo/assets/145053488/a70920c3-9047-4cea-aa15-e1568bd51ee1)

Studentų rūšiavimą į dvi grupes: 0.00965106666 sekundes
Grupiu įrašymas į failus: 0.0001688 sekundes

![282304731-ad588561-0792-405e-a3af-2c569d4e61ba](https://github.com/GabijaF/isnaujo/assets/145053488/f9bfd5ad-fa2b-4ed1-9476-e94c78b29335)

Studentų rūšiavimą į dvi grupes: 0.054231 sekundes
Grupiu įrašymas į failus: 0.00336386666 sekundes

![282304749-ac835221-9415-4c34-b6a1-b666c9549161](https://github.com/GabijaF/isnaujo/assets/145053488/b5aa8961-9e5e-4068-b71f-a860b6ddd30f)

Studentų rūšiavimą į dvi grupes: 0.465106 sekundes
Grupiu įrašymas į failus: 0.0699241 sekundes

![282304763-39f4934e-6867-4ab7-9d78-3c916f9dbc69](https://github.com/GabijaF/isnaujo/assets/145053488/2f827177-25ae-4873-ae71-bf1455e9818e)

Studentų rūšiavimą į dvi grupes: 4.29436333333 sekundes
Grupiu įrašymas į failus: 0.26172366666 sekundes

![282304791-3cc7bb5e-87a2-4114-adeb-8250b544bf12](https://github.com/GabijaF/isnaujo/assets/145053488/626ea36c-c2eb-4e63-b56d-3042faaa0596)

Studentų rūšiavimą į dvi grupes: 80.331 sekundes
Grupiu įrašymas į failus: 4.75924666667 sekundes
****


##std::list


