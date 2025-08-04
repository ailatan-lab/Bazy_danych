#include <iostream>
#include <mysql.h>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void wyswietl_budynki()
{
	system("cls");

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "ID | Firma Budowlana | Rok Budowu | Typ" << endl;

		string zapytanie = "SELECT b.BudynekID, fb.Nazwa, b.Rok_budowy, t.Nazwa FROM `budynek` AS b INNER JOIN `firmabudowlana` AS fb ON b.FirmaBudowlanaID = fb.FirmaID INNER JOIN `typ` AS t ON b.TypID = t.TypID";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);

}

void wyswietl_typy_budynkow()
{
	system("cls");

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "ID | Typ" << endl;

		string zapytanie = "SELECT * FROM `Typ`";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void wyswietl_firmy_budowlane()
{
	system("cls");

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "ID | Frima Budowlana" << endl;

		string zapytanie = "SELECT * FROM `firmabudowlana`";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);



	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << endl;
		cout << "Firmy bez budowy" << endl;
		cout << "ID | Frima Budowlana" << endl;

		string zapytanie = "SELECT fb.FirmaID, fb.Nazwa FROM `firmabudowlana` AS fb LEFT JOIN budynek AS b ON fb.FirmaID = b.FirmaBudowlanaID WHERE b.BudynekID IS NULL;";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void wyswietl_wlascicieli_firm_budowlanych()
{
	system("cls");

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "ID | Nazwa Firmy | Wlasciciel" << endl;

		string zapytanie = "SELECT fb.Nazwa, w.Nazwa FROM `wlascicielfirmy` AS wf INNER JOIN wlasciciel AS w ON wf.WlascicielFirmyID = w.WlascicielFirmyID INNER JOIN firmabudowlana AS fb ON wf.FirmaID = fb.FirmaID;";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void wyswietl_wlascicieli_firm_budujacych_budynek()
{
	system("cls");

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		cout << "ID | Nazwa Firmy | Wlasciciel" << endl;

		string zapytanie = "SELECT b.BudynekID, w.Nazwa FROM `wlascicielfirmy` AS wf INNER JOIN wlasciciel AS w ON wf.WlascicielFirmyID = w.WlascicielFirmyID INNER JOIN firmabudowlana AS fb ON wf.FirmaID = fb.FirmaID INNER JOIN budynek AS b ON b.FirmaBudowlanaID = fb.FirmaID;";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			MYSQL_RES* result = mysql_store_result(&mysql);

			if (result != NULL) {
				int num_fields = mysql_num_fields(result);
				MYSQL_ROW row;

				while ((row = mysql_fetch_row(result))) {
					for (int i = 0; i < num_fields; i++) {
						std::cout << row[i] << " ";
					}
					std::cout << std::endl;
				}

				mysql_free_result(result);
			}
			else {
				std::cerr << "B³¹d pobierania wyników zapytania: " << mysql_error(&mysql) << std::endl;
			}
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void dodawanie_budynku()
{
	system("cls");
	
	wyswietl_typy_budynkow();
	cout << "Wybierz typ budynku" << endl;
	int wybierzID;
	cin >> wybierzID;

	wyswietl_firmy_budowlane();
	cout << "Wybierz firme budowlana" << endl;
	int wybierzfirme;
	cin >> wybierzfirme;



	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		std::string nazwa = "Przyk³adowaNazwa";
		std::time_t czas_teraz = std::time(nullptr);
		std::tm czas_struktura = {};

		localtime_s(&czas_struktura, &czas_teraz); 

		int obecny_rok = czas_struktura.tm_year + 1900;

		std::string zapytanie = "INSERT INTO `budynek` (TypID, FirmaBudowlanaID, Rok_budowy) VALUES ('" + to_string(wybierzID) + "', " + to_string(wybierzfirme) + ", " + to_string(obecny_rok) + ")";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			std::cout << "Budynek zostal dodany" << std::endl;
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void usuwanie_busynku()
{
	system("cls");

	wyswietl_budynki();
	cout << "Wybierz budynek do usuniecia" << endl;
	int usun;
	cin >> usun;

	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {

		string zapytanie = "DELETE FROM `budynek` WHERE BudynekID =" + to_string(usun) + "";

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			std::cout << "Budynek zostal usuniety" << std::endl;
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void edytuj()
{
	system("cls");

	wyswietl_budynki();
	cout << "Wybierz budynek do edycji" << endl;
	int wybierzbudynek;
	cin >> wybierzbudynek;

	wyswietl_typy_budynkow();
	cout << "Wybierz typ budynku" << endl;
	int wybierzID;
	cin >> wybierzID;

	wyswietl_firmy_budowlane();
	cout << "Wybierz firme budowlana" << endl;
	int wybierzfirme;
	cin >> wybierzfirme;



	MYSQL mysql;

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, "localhost", "root", "", "projekt", 4306, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to database: Error: %s\n",
			mysql_error(&mysql));
	}
	else {
		std::string nazwa = "Przyk³adowaNazwa";
		std::time_t czas_teraz = std::time(nullptr);
		std::tm czas_struktura = {};

		localtime_s(&czas_struktura, &czas_teraz);

		int obecny_rok = czas_struktura.tm_year + 1900;

		std::string zapytanie = "UPDATE `budynek` SET TypID = " + std::to_string(wybierzID) + ", FirmaBudowlanaID = " + std::to_string(wybierzfirme) + " WHERE BudynekID = " + std::to_string(wybierzbudynek);

		if (mysql_query(&mysql, zapytanie.c_str()) == 0) {
			std::cout << "Budynek zostal edytowany" << std::endl;
		}
		else {
			std::cerr << "B³¹d wykonania zapytania: " << mysql_error(&mysql) << std::endl;
		}
	}


	mysql_close(&mysql);
}

void menu()
{
	cout << "1. Wyswietl budynki" << endl;
	cout << "2. Wyswietl typy budynko" << endl;
	cout << "3. Wyswietl firmy budowlane" << endl;
	cout << "4. Wyswietl wlascicieli fimr budowlanych" << endl;
	cout << "5. Wyswietl wlascicieli firm budujacych budynek" << endl;
	cout << "6. Dodaj budynek" << endl;
	cout << "7. Usun budynek" << endl;
	cout << "8. Edytuj budynek" << endl;
	cout << "0. Zamkniecie programu" << endl;

	int wybor_opcji;
	cout << "wybierz opcje" << endl;
	cin >> wybor_opcji;

	switch (wybor_opcji)
	{
	case 0:
		return;
	case 1:
		wyswietl_budynki();
		break;
	case 2:
		wyswietl_typy_budynkow();
		break;
	case 3:
		wyswietl_firmy_budowlane();
		break;
	case 4:
		wyswietl_wlascicieli_firm_budowlanych();
		break;
	case 5:
		wyswietl_wlascicieli_firm_budujacych_budynek();
		break;
	case 6:
		dodawanie_budynku();
		break;
	case 7:
		usuwanie_busynku();
		break;
	case 8:
		edytuj();
		break;
	default:
		cout << "Nie ma tekiej opcji" << endl;
		break;
	}


	cout << endl;
	cout << endl;
	menu();
}



int main()
{
	menu();


	return 0;
}