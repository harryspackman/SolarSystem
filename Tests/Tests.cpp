#include "pch.h"
#include "CppUnitTest.h"
#include "../SolarSystem/System.h"
#include "../SolarSystem/System.cpp"
#include "../SolarSystem/Body.h"
#include "../SolarSystem/Body.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
		

	public:
		
		TEST_METHOD(calculateBarycenterTest)
		{
			
			Body testBody1(1, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}); // 1kg mass stationary at position (0, 0, 0)
			Body testBody2(1, {1, 0, 0}, {0, 0, 0}, {0, 0, 0});	// 1kg mass stationary at position (1, 0, 0)			   
			
			vector<Body> Bodies = { testBody1, testBody2 };

			System system;

			double barry = system.findBarycenter(Bodies);

			Assert::AreEqual(barry, 0.5);

		}

	};
}
