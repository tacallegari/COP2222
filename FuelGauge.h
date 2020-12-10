
class FuelGauge
{
private:
	int fuel;
public:
	//Constructors
	FuelGauge();

	//Retrieves fuel
	int getFuel();

	//Functions
	void addFuel(); //Adds fuel

	void burnFuel(); //Decreases fuel

	void reportFuel(); //Reports fuel
};

