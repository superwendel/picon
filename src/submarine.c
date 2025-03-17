extern Submarine *submarine;

void Sub_DrainResources() 
{
    i32 oxygenDrain = 2;
    i32 fuelDrain = 1;
    
    if (submarine->upgrades.oxygenEfficiency) 
	{
        oxygenDrain -= 1; 
    }

    if (submarine->upgrades.fuelEfficiency) 
	{
        fuelDrain = 0; 
    }

    submarine->oxygen -= oxygenDrain;
    submarine->fuel -= fuelDrain;
    submarine->power -= 1;  // Power always drains
    submarine->morale -= (submarine->upgrades.moraleBoost ? 0 : 1); 

    // Morale drops if hull or oxygen are too low
    if (submarine->oxygen < 20) 
	{
        submarine->morale -= 5;
    }
    if (submarine->hull < 30) 
	{
        submarine->morale -= 5;
    }
}

void Sub_ApplyUpgrade(i32 choice) {
    switch (choice) {
        case 0: // Reinforced Hull
            submarine->upgrades.reinforcedHull = 1;
            submarine->hull += 20;
            break;
        case 1: // Advanced Oxygen Tank
            submarine->upgrades.oxygenEfficiency = 1;
            break;
        case 2: // Fuel Efficiency System
            submarine->upgrades.fuelEfficiency = 1;
            break;
    }
}