/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){}
		virtual ~tappityTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, samestring){
  std::string test = "abcdef";
  tappity mytap(test);
  mytap.entry(test);
  ASSERT_EQ(mytap.accuracy(), 100);
}

TEST(tappityTest, inputshorter){
  std::string input = "abcd";
  std::string ref = "abcdefgh";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.accuracy(), 50);
}

TEST(tappityTest, refshorter){
  std::string input = "abcd";
  std::string ref = "abcdefgh";
  tappity mytap(input);
  mytap.entry(ref);
  ASSERT_EQ(mytap.accuracy(), 50);
}

TEST(tappityTest, inputempty){
  std::string input = "";
  std::string ref = "abcdefgh";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.accuracy(), 0);
}

TEST(tappityTest, refempty){
  std::string input = "abc";
  std::string ref = "";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.accuracy(), 0);
}

TEST(tappityTest, bothepmty){
  std::string input = "";
  std::string ref = "";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.accuracy(), 100);
}

TEST(tappityTest, uneven){
  std::string input = "abcd";
  std::string ref = "abcdefghijk";
  tappity mytap(input);
  mytap.entry(ref);
  ASSERT_EQ(mytap.accuracy(), 36);
}

TEST(tappityTest, uninit){
  std::string input;
  std::string ref = "abc";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.accuracy(), 0);
}

TEST(tappityTest, bigstring){
  std::string input = "T";
  std::string ref = "The quick brown fox jumped over the lazy dog. esafjklafhdskljfhdasjk";
  tappity mytap(input);
  mytap.entry(ref);
  ASSERT_EQ(mytap.accuracy(), 1);
}

TEST(tappityTest, lengthdiff){
  std::string input = "a";
  std::string ref = "abc";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.length_difference(), 2);
}

TEST(tappityTest, lengthdiffempty){
  std::string input = "";
  std::string ref = "";
  tappity mytap(ref);
  mytap.entry(input);
  ASSERT_EQ(mytap.length_difference(), 0);
}
