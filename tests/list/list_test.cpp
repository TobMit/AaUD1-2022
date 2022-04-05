#include "list_test.h"

namespace tests
{
	// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}

	// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}

	// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}
	ListTestInsert::ListTestInsert() : SimpleTest("Insert")
	{
	}
	void ListTestInsert::test()
	{
		structures::ArrayList<int>* zoznam = new structures::ArrayList<int>;
		SimpleTest::logInfo("Vkladam 4 prvky na koniec zoznamu");
		zoznam->add(10);
		zoznam->add(20);
		zoznam->add(30);
		zoznam->add(40);
		SimpleTest::assertTrue(zoznam->size() == 4, "Pole ma velkost 4");

		SimpleTest::logInfo("Vkladam dalsie 4 prvky na koniec zoznamu");
		zoznam->add(100);
		zoznam->add(200);
		zoznam->add(300);
		zoznam->add(400);


		//SimpleTest::logInfo("Aktualna velkost pola je: " + std::to_string(zoznam->size()));
		SimpleTest::assertTrue(zoznam->size() == 8, "Pole ma velkost 8");

		SimpleTest::logInfo("Vkladam 9 prvkov pomocou insert");
		for (int i = 0; i < 9; i++)
		{
			zoznam->insert(1, 0);
		}
		SimpleTest::assertTrue(zoznam->size() == 17, "Pole ma velkost 17");
		zoznam->insert(7, 0);
		zoznam->insert(77, 4);
		zoznam->insert(777, 18);
		zoznam->insert(7777, 20);
		SimpleTest::assertTrue(zoznam->size() == 21, "Pole ma velkost 21");

		SimpleTest::assertTrue(zoznam->at(0) == 7, "Mala by tam byt 7 a je tam " + std::to_string(zoznam->at(0)));
		SimpleTest::assertTrue(zoznam->at(1) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(1)));
		SimpleTest::assertTrue(zoznam->at(2) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(2)));
		SimpleTest::assertTrue(zoznam->at(3) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(3)));
		SimpleTest::assertTrue(zoznam->at(4) == 77, "Mala by tam byt 77 a je tam " + std::to_string(zoznam->at(4)));
		SimpleTest::assertTrue(zoznam->at(5) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(5)));
		SimpleTest::assertTrue(zoznam->at(6) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(6)));
		SimpleTest::assertTrue(zoznam->at(7) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(7)));
		SimpleTest::assertTrue(zoznam->at(8) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(8)));
		SimpleTest::assertTrue(zoznam->at(9) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(9)));
		SimpleTest::assertTrue(zoznam->at(10) == 1, "Mala by tam byt 1 a je tam " + std::to_string(zoznam->at(10)));
		SimpleTest::assertTrue(zoznam->at(11) == 10, "Mala by tam byt 10 a je tam " + std::to_string(zoznam->at(11)));
		SimpleTest::assertTrue(zoznam->at(12) == 20, "Mala by tam byt 20 a je tam " + std::to_string(zoznam->at(12)));
		SimpleTest::assertTrue(zoznam->at(13) == 30, "Mala by tam byt 30 a je tam " + std::to_string(zoznam->at(13)));
		SimpleTest::assertTrue(zoznam->at(14) == 40, "Mala by tam byt 40 a je tam " + std::to_string(zoznam->at(14)));
		SimpleTest::assertTrue(zoznam->at(15) == 100, "Mala by tam byt 100 a je tam " + std::to_string(zoznam->at(15)));
		SimpleTest::assertTrue(zoznam->at(16) == 200, "Mala by tam byt 200 a je tam " + std::to_string(zoznam->at(16)));
		SimpleTest::assertTrue(zoznam->at(17) == 300, "Mala by tam byt 300 a je tam " + std::to_string(zoznam->at(17)));
		SimpleTest::assertTrue(zoznam->at(18) == 777, "Mala by tam byt 777 a je tam " + std::to_string(zoznam->at(18)));
		SimpleTest::assertTrue(zoznam->at(19) == 400, "Mala by tam byt 400 a je tam " + std::to_string(zoznam->at(19)));
		SimpleTest::assertTrue(zoznam->at(20) == 7777, "Mala by tam byt 7777 a je tam " + std::to_string(zoznam->at(20)));
		delete zoznam;
		
	}

// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());
		addTest(new ArryListInsert());
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
        addTest(new LinkedListInsert());
	}

// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		addTest(new LinkedListTestOverall());
		
	}

}