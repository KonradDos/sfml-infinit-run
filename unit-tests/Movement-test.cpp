#include <boost/test/unit_test.hpp>
#include <Movement.hpp>

BOOST_AUTO_TEST_CASE( IS_CHARACTER_ON_THE_GROUND ) 
{
    Movement m1(1, 3, 420, 200);

    BOOST_TEST(!m1.getGoesUpStatus());
    BOOST_TEST(!m1.getGoesDownStatus());
}

BOOST_AUTO_TEST_CASE( IS_CHARACTER_IN_THE_AIR ) 
{
    Movement m1(1, 3, 420, 200);
    m1.Jump();

    BOOST_TEST(m1.getGoesUpStatus());
}

BOOST_AUTO_TEST_CASE( RESET_VALUES ) 
{
    Movement m1(1, 3, 420, 200);
    m1.Jump();

    BOOST_TEST(m1.getGoesUpStatus());

    m1.resetStatus();
    BOOST_TEST(!m1.getGoesUpStatus());
}