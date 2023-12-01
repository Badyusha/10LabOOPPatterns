#include "GeoMap.hpp"
#include "Book.hpp"
#include "Newspaper.hpp"
#include "Notebook.hpp"
#include "Magazine.hpp"
#include "Unit.hpp"


float correctFloat() {
	for (;;) {
		float num;
		std::cin.unsetf(std::ios::skipws);
		std::cin >> num;

		if (std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			return num;
		}

		std::cin.clear();
		std::cin.ignore(10, '\n');

		std::cout << "\n��������� ������ ������������� �����!\n\n> ";
	}
}

int correctInteger() {
	for (;;) {
		int num;
		std::cin.unsetf(std::ios::skipws);
		std::cin >> num;

		if (std::cin.good()) {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			return num;
		}

		std::cin.clear();
		std::cin.ignore(10, '\n');

		std::cout << "\n��������� ������ ������������� �����!\n\n> ";
	}
}

std::string correctString() {
	for (;;) {
		std::string str;
		std::cin.unsetf(std::ios::skipws);
		getline(std::cin, str);
		std::string wrongSymbols = "0123456789/*+=)(*&^%$#@!?><~`'\"\\/";

		if (str.size() > 40) {
			std::cout << "\n������� ������� ������!\n������� �����: ";
			str = correctString();
		}

		if (str == "") {
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}

		for (int i = 0; i < wrongSymbols.size(); ++i) {
			if (find(str.begin(), str.end(), wrongSymbols[i]) != str.end()) {
				std::cout << "\n��������� ������ ��������� �������!\n\n> ";
				str = correctString();
			}
		}
		std::cin.clear();
		return str;
	}
}



int chooseProduct() {
	system("cls");

	std::cout << "�������� ���������\n"
		"1. �������������� �����\n"
		"2. �����\n"
		"3. ������\n"
		"4. �������\n"
		"5. ������\n"
		"0. �����\n\n> ";

	for(;;) {
		int choice = correctInteger();
		if (choice >= 0 && choice <= 5) { return choice; }
		std::cout << "\n\n�������� ��������!\n\n> ";
	}

}



static PaperProduct* makePaperProductFabricMethod(int paperProductType) {
	switch (paperProductType) {
	case PRODUCTS::GEO_MAP: {
		return new GeoMap();
	}
	case PRODUCTS::BOOK: {
		return new Book();
	}
	case PRODUCTS::NEWSPAPER: {
		return new Newspaper();
	}
	case PRODUCTS::NOTEBOOK: {
		return new Notebook();
	}
	case PRODUCTS::MAGAZINE: {
		return new Magazine();
	}
	}
}

static PaperProduct* makePaperProductFabricMethodWithArgs(const PaperProduct* paperProduct) {
	switch (paperProduct->paperProductsType()) {
		case PRODUCTS::GEO_MAP: {
			return new GeoMap(static_cast<const GeoMap*>(paperProduct));
		}
		case PRODUCTS::BOOK: {
			return new Book(static_cast<const Book*>(paperProduct));
		}
		case PRODUCTS::NEWSPAPER: {
			return new Newspaper(static_cast<const Newspaper*>(paperProduct));
		}
		case PRODUCTS::NOTEBOOK: {
			return new Notebook(static_cast<const Notebook*>(paperProduct));
		}
		case PRODUCTS::MAGAZINE: {
			return new Magazine(static_cast<const Magazine*>(paperProduct));
		}
	}
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	GeoMap::Register();
	Book::Register();
	Newspaper::Register();
	Notebook::Register();
	Magazine::Register();

	std::vector<PaperProduct*> paperProductsFabricMethodVector;
	std::vector<PaperProduct*> paperProductsFabricMethodWithArgumentsVector;
	std::vector<PaperProduct*> paperProductsFabricConstructor;
	std::vector<Unit*> unitsVector;
	std::vector<PaperProduct*> polimorphicCopyVector;


	for (;;) {
		std::cout << "�������� ����� ����\n"
					"1. ������� ������� � ������� ���������� ������\n"
					"2. ������� ������� � ������� ���������� ������ � �����������\n"
					"3. ������� ������� � ������� ���������� ������������\n"
					"4. ������� ������ ����� � ������� ����������� �������\n"
					"5. ������� ������� � ������� ������������ �����������\n"
					"6. ������� ���������� ��� ��������\n"
					"7. �������� ���������� �� �������� 1)\n"
					"8. ������� ��� �������\n"
					"9. �����\n\n> ";

		switch (correctInteger()) {
		case 1: {
			int productNum = chooseProduct();
			if (!productNum) {
				break;
			}
			paperProductsFabricMethodVector.push_back(makePaperProductFabricMethod(productNum - 1));

			std::cout << "\n������� ������!\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 2: {
			int productNum = chooseProduct();
			if (!productNum) {
				break;
			}

			switch (--productNum) {
				case PRODUCTS::GEO_MAP: {
					paperProductsFabricMethodWithArgumentsVector.push_back(new GeoMap());
					break;
				}
				case PRODUCTS::BOOK: {
					paperProductsFabricMethodWithArgumentsVector.push_back(new Book());
					break;
				}
				case PRODUCTS::NEWSPAPER: {
					paperProductsFabricMethodWithArgumentsVector.push_back(new Newspaper());
					break;

				}
				case PRODUCTS::NOTEBOOK: {
					paperProductsFabricMethodWithArgumentsVector.push_back(new Notebook());
					break;

				}
				case PRODUCTS::MAGAZINE: {
					paperProductsFabricMethodWithArgumentsVector.push_back(new Magazine());
					break;
				}
			}

			std::cout << "\n������� ������!\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 3: {
			int productNum = chooseProduct();
			if (!productNum) {
				break;
			}

			paperProductsFabricConstructor.push_back(PaperProduct::makePaperProduct(productNum - 1));

			std::cout << "\n������� ������!\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 4: {
			unitsVector.push_back(GeoMap::makeUnit());

			std::cout << "\n������� ������!\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 5: {
			int productNum = chooseProduct();
			if (!productNum) {
				break;
			}

			switch (--productNum) {
				case PRODUCTS::GEO_MAP: {
					polimorphicCopyVector.push_back((new GeoMap())->clone());
					break;
				}
				case PRODUCTS::BOOK: {
					polimorphicCopyVector.push_back((new Book())->clone());
					break;
				}
				case PRODUCTS::NEWSPAPER: {
					polimorphicCopyVector.push_back((new Newspaper())->clone());
					break;
				}
				case PRODUCTS::NOTEBOOK: {
					polimorphicCopyVector.push_back((new Notebook())->clone());
					break;

				}
				case PRODUCTS::MAGAZINE: {
					polimorphicCopyVector.push_back((new Magazine())->clone());
					break;
				}
			}

			std::cout << "\n������� ������!\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 6: {
			system("cls");

			for (const auto& elem : paperProductsFabricMethodVector) {
				if (auto map = dynamic_cast<GeoMap*>(elem); map) {
					std::cout << "������: " << map->getRegion() << ", �������: " << map->getScale() << std::endl;
					continue;
				}
				if (auto book = dynamic_cast<Book*>(elem); book) {
					std::cout << "����: " << book->getGenre() << ", ��� �������: " << book->getCoverType() << std::endl;
					continue;
				}
				if (auto newspaper = dynamic_cast<Newspaper*>(elem); newspaper) {
					std::cout << "����� �������: " << newspaper->getReleaseNumber() << ", ����������: " << std::boolalpha << newspaper->IsDaily() << std::endl;
					continue;
				}
				if (auto notebook = dynamic_cast<Notebook*>(elem); notebook) {
					std::cout << "�������: " << std::boolalpha << notebook->IsPlugIn() << ", ��� ��������: " << notebook->getType() << std::endl;
					continue;
				}
				if (auto magazine = dynamic_cast<Magazine*>(elem); magazine) {
					std::cout << "���������: " << std::boolalpha << magazine->IsSleek() << ", ���������: " << magazine->getCategory() << std::endl;
					continue;
				}
			}

			for (const auto& elem : paperProductsFabricMethodWithArgumentsVector) {
				if (auto map = dynamic_cast<GeoMap*>(elem); map) {
					std::cout << "������: " << map->getRegion() << ", �������: " << map->getScale() << std::endl;
					continue;
				}
				if (auto book = dynamic_cast<Book*>(elem); book) {
					std::cout << "����: " << book->getGenre() << ", ��� �������: " << book->getCoverType() << std::endl;
					continue;
				}
				if (auto newspaper = dynamic_cast<Newspaper*>(elem); newspaper) {
					std::cout << "����� �������: " << newspaper->getReleaseNumber() << ", ����������: " << std::boolalpha << newspaper->IsDaily() << std::endl;
					continue;
				}
				if (auto notebook = dynamic_cast<Notebook*>(elem); notebook) {
					std::cout << "�������: " << std::boolalpha << notebook->IsPlugIn() << ", ��� ��������: " << notebook->getType() << std::endl;
					continue;
				}
				if (auto magazine = dynamic_cast<Magazine*>(elem); magazine) {
					std::cout << "���������: " << std::boolalpha << magazine->IsSleek() << ", ���������: " << magazine->getCategory() << std::endl;
					continue;
				}
			}

			for (const auto& elem : paperProductsFabricConstructor) {
				if (auto map = dynamic_cast<GeoMap*>(elem); map) {
					std::cout << "������: " << map->getRegion() << ", �������: " << map->getScale() << std::endl;
					continue;
				}
				if (auto book = dynamic_cast<Book*>(elem); book) {
					std::cout << "����: " << book->getGenre() << ", ��� �������: " << book->getCoverType() << std::endl;
					continue;
				}
				if (auto newspaper = dynamic_cast<Newspaper*>(elem); newspaper) {
					std::cout << "����� �������: " << newspaper->getReleaseNumber() << ", ����������: " << std::boolalpha << newspaper->IsDaily() << std::endl;
					continue;
				}
				if (auto notebook = dynamic_cast<Notebook*>(elem); notebook) {
					std::cout << "�������: " << std::boolalpha << notebook->IsPlugIn() << ", ��� ��������: " << notebook->getType() << std::endl;
					continue;
				}
				if (auto magazine = dynamic_cast<Magazine*>(elem); magazine) {
					std::cout << "���������: " << std::boolalpha << magazine->IsSleek() << ", ���������: " << magazine->getCategory() << std::endl;
					continue;
				}
			}

			for (const auto& elem : polimorphicCopyVector) {
				if (auto map = dynamic_cast<GeoMap*>(elem); map) {
					std::cout << "������: " << map->getRegion() << ", �������: " << map->getScale() << std::endl;
					continue;
				}
				if (auto book = dynamic_cast<Book*>(elem); book) {
					std::cout << "����: " << book->getGenre() << ", ��� �������: " << book->getCoverType() << std::endl;
					continue;
				}
				if (auto newspaper = dynamic_cast<Newspaper*>(elem); newspaper) {
					std::cout << "����� �������: " << newspaper->getReleaseNumber() << ", ����������: " << std::boolalpha << newspaper->IsDaily() << std::endl;
					continue;
				}
				if (auto notebook = dynamic_cast<Notebook*>(elem); notebook) {
					std::cout << "�������: " << std::boolalpha << notebook->IsPlugIn() << ", ��� ��������: " << notebook->getType() << std::endl;
					continue;
				}
				if (auto magazine = dynamic_cast<Magazine*>(elem); magazine) {
					std::cout << "���������: " << std::boolalpha << magazine->IsSleek() << ", ���������: " << magazine->getCategory() << std::endl;
					continue;
				}
			}

			std::cout << "\n" << std::endl;
			system("pause");
			system("cls");
			break;
		}

		case 7: {
			int productNum = chooseProduct();
			if (paperProductsFabricMethodVector.empty()) {
				system("cls");
				std::cout << "\n\n�����!\n\n";
				break;
			}

			std::cout << "\n�������� ����� �������\n" << std::endl;

			int counter = 0;
			for (const auto& elem : paperProductsFabricMethodVector) {
				std::cout << ++counter << "\t";

				if (auto map = dynamic_cast<GeoMap*>(elem); map) {
					std::cout << "������: " << map->getRegion() << ", �������: " << map->getScale() << std::endl;
					continue;
				}
				if (auto book = dynamic_cast<Book*>(elem); book) {
					std::cout << "����: " << book->getGenre() << ", ��� �������: " << book->getCoverType() << std::endl;
					continue;
				}
				if (auto newspaper = dynamic_cast<Newspaper*>(elem); newspaper) {
					std::cout << "����� �������: " << newspaper->getReleaseNumber() << ", ����������: " << std::boolalpha << newspaper->IsDaily() << std::endl;
					continue;
				}
				if (auto notebook = dynamic_cast<Notebook*>(elem); notebook) {
					std::cout << "�������: " << std::boolalpha << notebook->IsPlugIn() << ", ��� ��������: " << notebook->getType() << std::endl;
					continue;
				}
				if (auto magazine = dynamic_cast<Magazine*>(elem); magazine) {
					std::cout << "���������: " << std::boolalpha << magazine->IsSleek() << ", ���������: " << magazine->getCategory() << std::endl;
					continue;
				}
			}

			int objectNum = correctInteger();
			while (objectNum < 1 || objectNum > paperProductsFabricMethodVector.size()) {
				std::cout << "\n�������� ����!\n\n> ";
				objectNum = correctInteger();
			}

			if (auto map = dynamic_cast<GeoMap*>(paperProductsFabricMethodVector.at(objectNum)); map) {
				std::cout << "������� ������: ";
				std::string region;
				getline(std::cin, region);
				std::cout << "������� �������: ";
				std::string scale;
				getline(std::cin, scale);
				map->setRegion(region);
				map->setScale(scale);

				std::cout << "\n\n������ ��������!\n\n";
				system("pause");
				system("cls");

				continue;
			}
			if (auto book = dynamic_cast<Book*>(paperProductsFabricMethodVector.at(objectNum)); book) {
				std::cout << "������� ����: ";
				std::string genre;
				getline(std::cin, genre);
				std::cout << "������� ��� �������: ";
				std::string cover;
				getline(std::cin, cover);
				book->setGenre(genre);
				book->setCoverType(cover);

				std::cout << "\n\n������ ��������!\n\n";
				system("pause");
				system("cls");				
				
				continue;
			}
			if (auto newspaper = dynamic_cast<Newspaper*>(paperProductsFabricMethodVector.at(objectNum)); newspaper) {
				std::cout << "������� ����� �������: ";
				int region;
				region = correctInteger();
				std::cout << "������ ����������?(0/1): ";
				bool scale;
				std::cin >> scale;
				newspaper->setReleaseNumber(region);
				newspaper->setIsDaily(scale);
				
				std::cout << "\n\n������ ��������!\n\n";
				system("pause");
				system("cls");

				continue;
			}
			if (auto notebook = dynamic_cast<Notebook*>(paperProductsFabricMethodVector.at(objectNum)); notebook) {
				std::cout << "������� �������?(0/1): ";
				bool region;
				std::cin >> region;
				std::cout << "��� ��������: ";
				std::string scale;
				getline(std::cin, scale);
				notebook->setIsPlugIn(region);
				notebook->setType(scale);

				std::cout << "\n\n������ ��������!\n\n";
				system("pause");
				system("cls");

				continue;
			}
			if (auto magazine = dynamic_cast<Magazine*>(paperProductsFabricMethodVector.at(objectNum)); magazine) {
				std::cout << "������ ���������?(0/1): ";
				bool region;
				std::cin >> region;
				std::cout << "��������� �������: ";
				std::string scale;
				getline(std::cin, scale);
				magazine->setIsSleek(region);
				magazine->setCategory(scale);

				std::cout << "\n\n������ ��������!\n\n";
				system("pause");
				system("cls");

				continue;
			}

			break;
		}

		case 8: {
			paperProductsFabricMethodVector.clear();
			paperProductsFabricMethodWithArgumentsVector.clear();
			paperProductsFabricConstructor.clear();
			unitsVector.clear();
			polimorphicCopyVector.clear();

			system("cls");
			std::cout << "�������� ���������!\n" << std::endl;

			break;
		}

		case 9: { return 0; }
		default: {
			std::cout << "\n�������� ����" << std::endl;
			std::cout << std::endl;
			system("pause");
			system("cls");
		}
		}
	}

	return 0;
}