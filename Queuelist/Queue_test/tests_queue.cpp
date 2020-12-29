#include "gtest.h"
#include "../Queuelist/Queue.h"

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> a);
}

TEST(Queue, can_copy_the_queue)
{
    TQueue<int> a;
    a.Push(3);
    ASSERT_NO_THROW(TQueue<int> copy(a));
}


TEST(Queue, can_assign_empty_queue)
{
    TQueue<int> a;
    TQueue<int> b;
    ASSERT_NO_THROW(a = b);
}
TEST(Queue, can_assign_queue_of_the_same_data_types)
{
    TQueue<int> a;
    TQueue<int> b;
    a.Push(5);
    a.Push(7);
    b.Push(3);
    ASSERT_NO_THROW(a = b);
}


TEST(Queue, can_compare_queue)
{
    TQueue<int> a;
    TQueue<int> b;
    a.Push(5);
    b.Push(3);
    ASSERT_NO_THROW(b == a);
}

TEST(Queue, comparing_the_queue_with_itself_gives_the_truth)
{
    TQueue<int> a;
    EXPECT_EQ(true, a == a);
}

TEST(Queue, comparing_the_same_queue_gives_the_truth)
{
    TQueue<int> a;
    TQueue<int> b;
    a.Push(3);
    b.Push(3);
    EXPECT_EQ(true, a == b);
}

TEST(Queue, comparing_different_queue_gives_the_lie)
{
    TQueue<int> a;
    TQueue<int> b;
    a.Push(3);
    EXPECT_EQ(true, a != b);
}
TEST(Queue, can_check_the_queue_for_emptiness)
{
    TQueue<int> a;
    ASSERT_NO_THROW(a.Empty());
}
TEST(Queue, initially_the_queue_is_empty)
{
    TQueue<int> a;
    a.Push(3);
    a.GetHead();
    EXPECT_EQ(true, a.Empty());
}
TEST(Queue, checking_for_the_emptiness_of_a_non_empty_queue_returns_false)
{
    TQueue<int> a;
    a.Push(3);
    EXPECT_EQ(false, a.Empty());
}
TEST(Queue, can_add_an_item_to_an_incomplete_queue)
{
    TQueue<int> a;
    ASSERT_NO_THROW(a.Push(3));
}
TEST(Queue, can_see_what_is_at_the_top_of_a_non_empty_queue)
{
    TQueue<int> a;
    a.Push(3);
    ASSERT_NO_THROW(a.SeeHead());
}
TEST(Queue, viewing_the_top_of_the_queue_does_not_change_the_state_of_the_stack)
{
    TQueue<int> a;
    a.Push(3);
    int b = a.SeeHead();
    EXPECT_EQ(b, a.SeeHead());
}
TEST(Queue, cant_look_at_the_top_of_an_empty_queue)
{
    TQueue<int> a;
    ASSERT_ANY_THROW(a.SeeHead());
}
TEST(Queue, can_take_an_element_from_a_non_empty_non_empty_queue)
{
    TQueue<int> a;
    a.Push(3);
    ASSERT_NO_THROW(a.GetHead());
}
TEST(Queue, taking_an_element_from_the_queue_reduces_its_size_by_one)
{
    TQueue<int> a;
    a.Push(3);
    a.GetHead();
    EXPECT_EQ(true, a.Empty());
}
TEST(Queue, cant_take_an_element_from_an_empty_queue)
{
    TQueue<int> a;
    ASSERT_ANY_THROW(a.GetHead());
}