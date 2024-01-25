/**
 * @file resistor.h - Header file containing abstract base circuit class and subclasses
 * @author Adolfo Hernandez
 * @date 12-3-2023
*/

//  Beginning of header guards for header file
#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream> // Includes access to input/output stream
#include <vector> // Includes access to vector data structure

// Beginning of project namespace-- encapsulates base and sub classes
namespace project {

    /**
     * @class Abstract circuit class serves as base simulation of a circuit
     * @brief Used for inheritance from other classes, includes destructor for memory
     * management. 
    */
    class Circuit {
    public:
        virtual double get_resistance() const = 0;
        virtual ~Circuit() {} // *Destructor *
    };

    /**
     * @class Resistor subclass-- inherits from Circuit class
     * @brief Serves as the blueprint for a resistor
    */
    class Resistor : public Circuit {
    private:
        double const resistance_; // Stores resistance value privately
    public:
        Resistor(double initResistance); // *Constructor*
        double get_resistance() const; // Return value of resistance
    };

    /**
     * @class Serial subclass -- inherits from Circuit class 
     * @brief Serves as the blueprint for a multiple circuits
    */
    class Serial : public Circuit {
    private:
        std::vector<Circuit*> objectMemory_; // Private vector containing memory addresses of circuits
    public:
        ~Serial(); // *Destructor*
        void append_object(Circuit* object); // Appends memory addres to the vector 
        double get_resistance() const override; // Calculates and returns total circuits resistance
    };
    /**
     * @class Serial subclass -- inherits from base Circuit class
    */
    class Parallel : public Circuit {
    private:
        std::vector<Circuit*> objects_; // Stores memory addresses in private vector
    public:
        ~Parallel(); // *Destructor*
        void append_object(Circuit* object); // Appends memory address to private vector
        double get_resistance() const override; // // Calculates and returns total resistance
    };
} // End of project namespace

#endif // RESISTOR_H

