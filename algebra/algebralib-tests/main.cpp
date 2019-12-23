#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
	uint64_t res = RUN_ALL_TESTS();
    return res;
}
