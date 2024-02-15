#include <iostream>
#include <cstdint>
#include <catch2/catch_test_macros.hpp>

#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("check list push and pop methods", "[list]")
{
    SECTION("method push back")
    {
        List l;
        CHECK (l.Size()==0 );
        
        l.PushBack(5);
        REQUIRE ( l.Size()==1);

        l.PushBack(7);
        l.PushBack(3);
        l.PushBack(8);
        l.PushBack(15);
        REQUIRE(l.Size() == 5);
    }
    SECTION("method push front")
    {
        List l;
        CHECK(l.Size() == 0);

        l.PushFront(1);
        REQUIRE(l.Size() == 1);
        
        l.PushFront(2);
        l.PushFront(4);
        l.PushFront(0);
        l.PushFront(235);
        REQUIRE(l.Size() == 5);
    }
    SECTION("method pop back") {
        List l;
        CHECK(l.Size() == 0);

        l.PopBack();
        INFO("PopBack on empty list");
        CHECK(l.Size() == 0);

        l.PushBack(5);
        l.PushBack(7);
        l.PushBack(3);
        l.PushBack(8);
        l.PushBack(15);
        REQUIRE(l.Size() == 5);

        l.PopBack();
        REQUIRE(l.Size() == 4);

        l.PopBack();
        l.PopBack();
        l.PopBack();
        REQUIRE(l.Size() == 1);
    }
    SECTION("method pop front") {
        List l;
        CHECK(l.Size() == 0);
        l.PopFront();
        INFO("PopFront on empty list");
        CHECK(l.Size() == 0);


        l.PushBack(5);
        l.PushBack(7);
        l.PushBack(3);
        l.PushBack(8);
        l.PushBack(15);
        l.PushBack(25);
        REQUIRE(l.Size() == 6);

        l.PopFront();
        REQUIRE(l.Size() == 5);

        l.PopFront();
        l.PopFront();
        REQUIRE(l.Size() == 3);
    }
    SECTION("all methods") {
        List l;
        CHECK(l.Size() == 0);

        l.PopBack();
        INFO("PopBack on empty list");
        CHECK(l.Size() == 0);
        l.PopFront();
        INFO("PopFront on empty list");
        CHECK(l.Size() == 0);
        l.PushBack(2);
        CHECK(l.Size() == 1);
        l.PopBack();
        CHECK(l.Size() == 0);
        l.PushBack(2);
        l.PopFront();
        CHECK(l.Size() == 0);
        l.PushFront(6);
        l.PopFront();
        CHECK(l.Size() == 0);
    }

}


