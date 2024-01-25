#include "resistor.h"
#include <iostream>

//g++ -o main main.cpp resistor.cpp -std=c++11


int main () {

   // TEST CASE 1
   // Creation of circuit_one object -- raw pointer allocated
   auto* circuit_one = new project::Parallel();

   // Appends resistor object to circuit_one -- test case of 100 ohms used
   circuit_one->append_object(new project::Resistor(100.0));

   // Creation of circuit_two object -- raw pointer allocated
   auto* circuit_two = new project::Serial();

   // Appends two resistor objects -- test cases of 100 and 200 ohms used
   circuit_two->append_object(new project::Resistor(100.0));
   circuit_two->append_object(new project::Resistor(200.0));

   // Adds the circuit_two object to the circuit_one object
   circuit_one->append_object(circuit_two);

    // Output print resistance 
   std::cout << "TEST CASE 1 Resistance is: "
             << circuit_one->get_resistance()  << std::endl;

    // Raw pointed deallocated 
    delete circuit_one;

    // TEST CASE 2
    auto* circuit_one_t2 = new project::Parallel();
    
    // Creation of three resistor objects -- test cases of 25, 60.5, and 90 ohms used
    circuit_one_t2->append_object(new project::Resistor(25.0)); 
    circuit_one_t2->append_object(new project::Resistor(60.5)); 
    circuit_one_t2->append_object(new project::Resistor(90.0)); 

    // Creation of circuit_two object -- raw pointer allocated
    auto* circuit_two_t2 = new project::Serial();

    // Creation of three resistor objects -- test cases of 30, 75, and 100 ohms used
    circuit_two_t2->append_object(new project::Resistor(30.0)); 
    circuit_two_t2->append_object(new project::Resistor(75.0)); 
    circuit_two_t2->append_object(new project::Resistor(100.0)); 

    // Creation of circuit_three object -- raw pointer allocated
    auto* circuit_three_t2 = new project::Serial();

    // Creation of two resistor objects -- test cases of 40 ohms used
    circuit_three_t2->append_object(new project::Resistor(40.0)); 
    circuit_three_t2->append_object(new project::Resistor(40.0)); 

    // Add circuit_two and circuit_three to circuit_one
    circuit_one_t2->append_object(circuit_two_t2);
    circuit_one_t2->append_object(circuit_three_t2);

    // Lower resistor added to circuit_one -- test case of 16.5 ohms used
    circuit_one_t2->append_object(new project::Resistor(16.5));

    // Output the total resistance of the circuit
    std::cout << "TEST CASE 2 Resistance is: "
              << circuit_one_t2->get_resistance() << std::endl;

    // Deallocate memory
    delete circuit_one_t2;

    // TEST CASE 3
    auto* circuit_one_t3 = new project::Parallel();
    
    // Creation of the first circuit
    circuit_one_t3->append_object(new project::Resistor(25.0));
    
    // Creation of the first serial circuit
    auto* circuit_two_t3 = new project::Serial();
    circuit_two_t3->append_object(new project::Resistor(10.0));
    circuit_two_t3->append_object(new project::Resistor(15.0));

    // Creation of the second serial circuit
    auto* circuit_three_t3 = new project::Serial();
    circuit_three_t3->append_object(new project::Resistor(40.0));
    circuit_three_t3->append_object(new project::Resistor(9.0));

    // Creation of the third serial circuit
    auto* circuit_four_t3 = new project::Serial();
    circuit_four_t3->append_object(new project::Resistor(5.0));
    circuit_four_t3->append_object(new project::Resistor(6.75));

    // Creation of the fourth serial circuit
    auto* circuit_five_t3 = new project::Serial();
    circuit_five_t3->append_object(new project::Resistor(77.0));

    // Creation of the fifth serial circuit
    auto* circuit_six_t3 = new project::Serial();
    circuit_six_t3->append_object(new project::Resistor(8.25));
    circuit_six_t3->append_object(new project::Resistor(6.45));

    // combine the second and third serial circuits in parallel
    auto* parallel_section_t3 = new project::Parallel();
    parallel_section_t3->append_object(circuit_three_t3);
    parallel_section_t3->append_object(circuit_four_t3);

    // Adding of circuits
    circuit_one_t3->append_object(circuit_two_t3);
    circuit_one_t3->append_object(parallel_section_t3);
    circuit_one_t3->append_object(circuit_five_t3);
    circuit_one_t3->append_object(circuit_six_t3);

    // Creation of the bottom serial circuit that will be in series with the main parallel circuit
    auto* bottom_series_t3 = new project::Serial();
    bottom_series_t3->append_object(new project::Resistor(11.5));
    bottom_series_t3->append_object(new project::Resistor(33.5));

    // Adding the bottom series to the main parallel circuit and then calculating the total resistance
    auto* main_circuit_t3 = new project::Serial();
    main_circuit_t3->append_object(circuit_one_t3);
    main_circuit_t3->append_object(bottom_series_t3);

    // Output the total resistance of the circuit
    std::cout << "TEST CASE 3 Resistance is: "
              << main_circuit_t3->get_resistance() << std::endl;

    // Deallocate memory
    delete main_circuit_t3;
    
    return 0;
}