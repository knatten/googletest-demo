#include "..\NoFlyList\NoFlyPolicy.h"
#include "..\NoFlyList\Person.h"

#include <gtest\gtest.h>

#include <memory>
#include <string>

using std::make_shared;
using std::string;

class NoFlyPolicyTest : public ::testing::Test
{
public:
	NoFlyPolicyTest() : person(Person::AMERICAN, Person::CONSERVATIVE) {};
protected:
	NoFlyPolicy policy;
	Person person;
};

TEST_F(NoFlyPolicyTest, niceGuysCanFly)
{
	ASSERT_TRUE(policy.canFly(person));
}

TEST_F(NoFlyPolicyTest, terroristsCannotFly)
{
	person.markAsTerrorist();
	ASSERT_FALSE(policy.canFly(person));
}

TEST_F(NoFlyPolicyTest, frenchLiberalsCannotFly)
{
	Person frenchLiberal(Person::FRENCH, Person::LIBERAL);
	ASSERT_FALSE(policy.canFly(frenchLiberal));
}

TEST_F(NoFlyPolicyTest, personWhoDidntTweetCanFly)
{
	auto twitter = make_shared<Twitter>();
	person.connectTwitterAccount(twitter);
	ASSERT_TRUE(policy.canFly(person));
}

TEST_F(NoFlyPolicyTest, personWhoTweetedSometingInnocentCanFly)
{
	auto twitter = make_shared<Twitter>();
	twitter->tweet("OMG SUPERBOWL IS NICE GOD BLESS BUD!!!!11");
	person.connectTwitterAccount(twitter);
	ASSERT_TRUE(policy.canFly(person));
}

class NoFlyPolicyTestWithTweets : public NoFlyPolicyTest, public ::testing::WithParamInterface<string> {};

TEST_P(NoFlyPolicyTestWithTweets, personWhoTweetedSometingBadCannotFly)
{
	auto twitter = make_shared<Twitter>();
	twitter->tweet(GetParam());
	person.connectTwitterAccount(twitter);
	ASSERT_FALSE(policy.canFly(person));
}

INSTANTIATE_TEST_CASE_P(_, NoFlyPolicyTestWithTweets, ::testing::Values("bomb", "osama", "obama"));

::testing::AssertionResult isBadPlace(const Destination& d)
{
	if (d.nofHumanRights == 0)
		return ::testing::AssertionSuccess();
	else
		return ::testing::AssertionFailure() << d << " has " << d.nofHumanRights << " human rights, expected 0";
}

TEST_F(NoFlyPolicyTest, terroristsGoToABadPlace)
{
	Destination d = policy.terroristDestination();
	ASSERT_TRUE(isBadPlace(d));
}

void assertIsBadPlace(const Destination& d)
{
	ASSERT_EQ(0, d.nofHumanRights);
}

TEST_F(NoFlyPolicyTest, terroristsGoToABadPlace2)
{
	Destination d = policy.terroristDestination();
	assertIsBadPlace(d);
}

TEST_F(NoFlyPolicyTest, terroristsGoToGitmo)
{
	Destination d = policy.terroristDestination();
	Destination gitmo("Guantanamo", 0);
	ASSERT_EQ(gitmo, d);
}