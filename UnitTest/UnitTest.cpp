#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
// #include "C:\Users\tmaks\code\ООП\lap ap 12.8it\lap ap 12.8it\lab ap 12.8it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreateRecommendedList)
		{
			std::Textbook* textbookList = nullptr;
			addTextbook(textbookList, "Author 1", "Book 1", 10);
			addTextbook(textbookList, "Author 2", "Book 2", 5);
			addTextbook(textbookList, "Author 3", "Book 3", 12);
			addTextbook(textbookList, "Author 4", "Book 4", 8);
			addTextbook(textbookList, "Author 5", "Book 5", 15);

			int minApprovalCount = 10;
			Textbook* recommendedList = createRecommendedList(textbookList, minApprovalCount);

			// Verify the recommended list contains the expected textbooks
			Assert::AreEqual(2, getCount(recommendedList)); // Assuming the expected count is 2

			// Clean up memory
			freeTextbookList(textbookList);
			freeTextbookList(recommendedList);
		}

		TEST_METHOD(TestPrintTextbookList)
		{
			Textbook* textbookList = nullptr;
			addTextbook(textbookList, "Author 1", "Book 1", 10);
			addTextbook(textbookList, "Author 2", "Book 2", 5);
			addTextbook(textbookList, "Author 3", "Book 3", 12);

			// Redirect cout to a stringstream for testing output
			std::stringstream outputStream;
			std::streambuf* oldCoutBuffer = std::cout.rdbuf(outputStream.rdbuf());

			printTextbookList(textbookList);

			// Restore cout
			std::cout.rdbuf(oldCoutBuffer);

			// Verify the output matches the expected output
			std::string expectedOutput =
				"Author: Author 1\n"
				"Name: Book 1\n"
				"Number of positive reviews: 10\n"
				"-----------------------\n"
				"Author: Author 2\n"
				"Name: Book 2\n"
				"Number of positive reviews: 5\n"
				"-----------------------\n"
				"Author: Author 3\n"
				"Name: Book 3\n"
				"Number of positive reviews: 12\n"
				"-----------------------\n";

			Assert::AreEqual(expectedOutput, outputStream.str());

			// Clean up memory
			freeTextbookList(textbookList);
		}
	};
}
