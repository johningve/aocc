#include <string.h>
#include <aoc/hashmap.h>
#include <unity.h>

HASHMAP_DECLARE_TYPE_NAME(char *, char *, str_str)

HASHMAP_IMPL_TYPE_NAME(char *, char *, str_str, hash_str, strcmp)

hashmap_str_str_t m;

void setUp()
{
	m = hashmap_str_str_new_with_capacity(4);
}

void tearDown()
{
	hashmap_str_str_free(&m);
}

void test_hashmap_insert_and_get()
{
	hashmap_str_str_insert(&m, "hello", "world", NULL, NULL);
	char *value;
	TEST_ASSERT(hashmap_str_str_get(&m, "hello", &value));
	TEST_ASSERT_EQUAL_STRING("world", value);
}

void test_hashmap_rehash()
{
	hashmap_str_str_insert(&m, "1", "1", NULL, NULL);
	hashmap_str_str_insert(&m, "2", "2", NULL, NULL);
	hashmap_str_str_insert(&m, "3", "3", NULL, NULL);
	hashmap_str_str_insert(&m, "4", "4", NULL, NULL);
	hashmap_str_str_insert(&m, "5", "5", NULL, NULL);

	char *value;
	TEST_ASSERT(hashmap_str_str_get(&m, "1", &value));
	TEST_ASSERT_EQUAL_STRING("1", value);
	TEST_ASSERT(hashmap_str_str_get(&m, "2", &value));
	TEST_ASSERT_EQUAL_STRING("2", value);
	TEST_ASSERT(hashmap_str_str_get(&m, "3", &value));
	TEST_ASSERT_EQUAL_STRING("3", value);
	TEST_ASSERT(hashmap_str_str_get(&m, "4", &value));
	TEST_ASSERT_EQUAL_STRING("4", value);
	TEST_ASSERT(hashmap_str_str_get(&m, "5", &value));
	TEST_ASSERT_EQUAL_STRING("5", value);
}

void test_hashmap_remove()
{
	hashmap_str_str_insert(&m, "1", "1", NULL, NULL);

	char *value;
	TEST_ASSERT(hashmap_str_str_remove(&m, "1", NULL, &value));
	TEST_ASSERT_EQUAL_STRING("1", value);
	TEST_ASSERT_FALSE(hashmap_str_str_get(&m, "1", &value));
}

int main()
{
	UNITY_BEGIN();
	RUN_TEST(test_hashmap_insert_and_get);
	RUN_TEST(test_hashmap_rehash);
	RUN_TEST(test_hashmap_remove);
	return UNITY_END();
}