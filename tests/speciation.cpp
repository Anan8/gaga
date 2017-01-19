#include "../gaga.hpp"
#include "catch/catch.hpp"
#include "dna.hpp"

template <typename T> void speciationGA() {
	GAGA::GA<T> ga(0, nullptr);
	ga.setVerbosity(0);
	ga.setEvaluator([](auto &i) { i.fitnesses["value"] = i.dna.value; });
	REQUIRE((ga.population.size() == 0));
	ga.setPopSize(400);
	ga.initPopulation([]() { return T::random(); });
	REQUIRE(ga.population.size() == 400);
	ga.step(10);
	REQUIRE(ga.population.size() == 400);
}
TEST_CASE("Classic optimization with speciation enabled", "[population]") {
	speciationGA<IntDNA>();
}