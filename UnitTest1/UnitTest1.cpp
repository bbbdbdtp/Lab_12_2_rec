#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_2_rec/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(hasDuplicatePairTest)
        {
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, 2, 3, 4, 5, 2 };
            int size = sizeof(values) / sizeof(values[0]);

            createList(head, tail, values, values, size);

            bool result = hasDuplicatePair(head);

            Assert::IsTrue(result);

            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    };
}