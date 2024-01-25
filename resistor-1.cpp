/**
 * @file resistor.cpp - Implementation of methods and members contained in resistor.h
 * @author Adolfo Hernandez
 * @date 12-2-23
*/
#include "resistor.h" // Inclusion of resistor header file -- contains base and subclasses.

// Beginning of project namespace -- encapsulates base and sub classes 
namespace project {

    // Definition of Resistor constructor
    Resistor::Resistor(double initResistance) : resistance_{ initResistance } {}

    // Function caluclates resistance and returns the resistor_ value
    double Resistor::get_resistance() const {
        return resistance_;
    }

    // Serial subclass Destructor -- dealllocates memory
    Serial::~Serial() {
        for (Circuit* const memory : objectMemory_) {
            delete memory;
        }
    }

    // Function appends memory address to vector
    void Serial::append_object(Circuit* object) {
        objectMemory_.push_back(object);
    }

    double Serial::get_resistance() const {
        auto total = 0.0;
        for (const Circuit* memory : objectMemory_) {
            total += memory->get_resistance();
        }
        return total;
    }

    // Parallel subclass destructor -- deallocates memory
    Parallel::~Parallel() {
        for (Circuit* memory : objects_) {
            delete memory;
        }
    }

    // Function appends memory address to Parallel subclass vector
    void Parallel::append_object(Circuit* object) {
        objects_.push_back(object);
    }
    
    // Function calculates and returns resistance
    double Parallel::get_resistance() const { 
        auto total = 0.0;
        for (const Circuit* object : objects_) {
            total += 1 / object->get_resistance();
        }
        if (total != 0) {
            return 1 / total;
        } else {
            return 0;
        }
    }

} // End of project namespace
