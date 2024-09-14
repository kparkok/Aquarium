// ICS 212: Project #2 - Karina Park-Okuna

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

//Homework #7: DEFINE CLASS
class AquariumAnimal {
private:
    string species;
    string habitat;
    string countryOfOrigin; // Originating country
    string diet; // carnivore, herbivore, omnivore

    string name;
    int age; // years
    int DOB; // Format: MMDDYY

    double weight; // kg
    double height; // cm

    bool isEndangered; // animal is endangered

    //Other data
    double temperaturePreference; // degrees fahrenheit
    int lifespan; // years
    bool isNocturnal; // active at night
    string colorPattern;
    string animalID; // unique animal id

//Homework #7: Constructors (4)
public:
    static int totalAnimals; // Total animals

    //no-arg/default constructor
    AquariumAnimal() {
        initialize("none", "none", "none", "none", "none", 0, 0, 0, 0, false, 0, 0, false, "none", "none");
    }

    //Creates animal with basic identifications
    AquariumAnimal(string na, int dob, double wei, double hei, string color, string id){
        AquariumAnimal(na, "none", "none", "none", na, 0, 0, wei, hei, false, 0, 0, false, color, id);
    }

    //Creates animal with some identifications
    AquariumAnimal(string sp, string hab, string country, string na, double wei, double hei, double tempPref, bool noct, string color, string id){
        AquariumAnimal(sp, hab, country, "none", na, 0, 0, wei, hei, false, 0, 0, noct, color, id);
    }

    // All identifications
    AquariumAnimal(string sp, string hab, string country, string di, string na, int ag, int dob, double wei, double hei, bool isEnd, double tempPref, int lifeSp, bool noct, string color, string id) {
        initialize(sp, hab, country, di, na, ag, dob, wei, hei, isEnd, tempPref, lifeSp, noct, color, id);
    }


    void initialize(string sp, string hab, string country, string di, string na, int ag, int dob, double wei, double hei, bool isEnd, double tempPref, int lifeSp, bool noct, string color, string id) {
        species = sp;
        habitat = hab;
        countryOfOrigin = country;
        diet = di;
        name = na;
        age = ag;
        DOB = dob;
        weight = wei;
        height = hei;
        isEndangered = isEnd;
        temperaturePreference = tempPref;
        lifespan = lifeSp;
        isNocturnal = noct;
        colorPattern = color;
        animalID = id;
        setSpecies(sp);
        totalAnimals++;
    }

    //Homework #10:
    virtual string getMovement() const {
        return "This animal moves in a typical way.";
    }

    virtual string makeSound() const {
        return "This animal makes a generic sound.";
    }

    //Homework #7: Get and Set methods (4)

    
    string getSpecies() const {
        return species;
    }

    void setSpecies(string species) {
        if (species.length() <= 2) {
            throw invalid_argument("Species length must be greater than 2");
        }
        this->species = species;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        if (name.length() <= 2) {
            throw invalid_argument("Name length must be greater than 2");
        }
        this->name = name;
    }

    string getHabitat() const {
        return habitat;
    }

    void setHabitat(string habitat) {
        if (habitat.length() <= 2) {
            throw invalid_argument("Habitat length must be greater than 2");
        }
        this->habitat = habitat;
    }

    string getDiet() const {
        return diet;
    }

    void setDiet(string diet) {
        if (diet == "omnivore" || diet == "herbivore" || diet == "carnivore") {
            this->diet = diet;
        } else {
            throw invalid_argument("Diet must be 'omnivore', 'herbivore', or 'carnivore'");
        }
    }
    //Returns profile of animal
    virtual string getAnimalProfile() const {
        ostringstream profile;
        profile << "Species: " << species << "\n"
                << "Habitat: " << habitat << "\n"
                << "Country of Origin: " << countryOfOrigin << "\n"
                << "Diet: " << diet << "\n"
                << "Name: " << name << "\n"
                << "Age: " << age << "\n"
                << "DOB: " << DOB << "\n"
                << "Weight: " << weight << " kg\n"
                << "Height: " << height << " cm\n"
                << "Endangered: " << (isEndangered ? "Yes" : "No") << "\n"
                << "Temperature Preference: " << temperaturePreference << " degrees Fahrenheit\n"
                << "Lifespan: " << lifespan << " years\n"
                << "Nocturnal: " << (isNocturnal ? "Yes" : "No") << "\n"
                << "Color Pattern: " << colorPattern << "\n"
                << "Animal ID: " << animalID;
        return profile.str();
    }

    //Homework 8: Overload 2 methods
    // Overloading "==" to compare age
    bool operator==(int otherAge) const {
        return this->age == otherAge;
    }
    // Overloading "<" to compare weight
    bool operator<(const AquariumAnimal& other) const {
        return this->weight < other.weight;
    }

};

class Fish : public AquariumAnimal {
    private:
        string waterType;
        int finCount;
        string scaleType;

    public:
        //No-arg constructor
        Fish() : AquariumAnimal(), waterType("unknown"), finCount(0), scaleType("unknown") {
        // This calls the no-arg constructor of the AquariumAnimal class
        }
        // Parameterized constructor
        Fish(string sp, string hab, string country, string di, string na, int ag, int dob, double wei, double hei, bool isEnd, double tempPref, int lifeSp, bool noct, string color, string id, string water, int fins, string scales)
        : AquariumAnimal(sp, hab, country, di, na, ag, dob, wei, hei, isEnd, tempPref, lifeSp, noct, color, id), waterType(water), finCount(fins), scaleType(scales) {
        // This calls the parameterized constructor of the AquariumAnimal class
        }

        //Homework #10:
        string getMovement() const {
        return "Swims by moving fins and tail.";
        }

        string makeSound() const {
            return "Makes bubbling sounds.";
        }

        //Homework #9: Get and Set methods
        string getWaterType() const {
        return waterType;
        }

        int getFinCount() const {
            return finCount;
        }

        string getScaleType() const {
            return scaleType;
        }

        void setWaterType(string type) {
            if (type == "freshwater" || type == "saltwater") {
                waterType = type;
            } else {
                throw invalid_argument("Water type must be either 'freshwater' or 'saltwater'");
            }
        }

        void setFinCount(int count) {
            if (count >= 0) {
                finCount = count;
            } else {
                throw invalid_argument("Fin count cannot be negative");
            }
        }

        void setScaleType(string type) {
            if (type == "smooth" || type == "rough" || type == "spiny") {
                scaleType = type;
            } else {
                throw invalid_argument("Scale type must be 'smooth', 'rough', or 'spiny'");
            }
        }


    };

    void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int AquariumAnimal::totalAnimals = 0;





int main() {
    // Example
    AquariumAnimal animal1("Shark", "Ocean", "Australia", "Carnivore", "Bruce", 10, 120599, 150.0, 300.0, false, 70.0, 30, false, "Grey", "SH001");
    AquariumAnimal animal2("Dolphin", "Ocean", "Australia", "Carnivore", "Flipper", 5, 120599, 150.0, 300.0, false, 70.0, 30, false, "Grey", "DL001");

    //Output of Homework #7: Animal Profile
    cout << animal1.getAnimalProfile() << endl;

    //Output of Homework #8: Overload method
    cout << "Comparing by age: " << (animal1 == 5 ? "Same" : "Different") << endl;
    cout << "Comparing by weight: ";
    if (animal1 < animal2) {
        cout << "Animal1 is lighter than Animal2" << endl;
    } else {
        cout << "Animal1 is not lighter than Animal2" << endl;
    }
    
    //Homework #9: Subclass Fish
    Fish fish1("Goldfish", "Tank", "China", "Herbivore", "Goldie", 1, 101020, 0.1, 5.0, false, 72.0, 10, false, "Golden", "GF001", "freshwater", 7, "smooth");
    cout << fish1.getAnimalProfile() << endl;

    try {
        fish1.setWaterType("brackish");
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    //Homework #10: Polymorphism
    AquariumAnimal* animal = new Fish("Goldfish", "Tank", "China", "Herbivore", "Goldie", 1, 101020, 0.1, 5.0, false, 72.0, 10, false, "Golden", "GF001", "freshwater", 7, "smooth");

    vector<AquariumAnimal*> animals; //Dynamic storage: Vector
    int userChoice;
    bool run = true;

    //user input of data needed for animal creation
    string species, habitat, country, diet, name, colorPattern, animalID;
    int age, DOB;
    double weight, height, temperaturePreference;
    int lifespan;
    bool isEndangered, isNocturnal;

    string waterType;
    int finCount;
    string scaleType;

    string type;

    int indexCase2 = 0;
    int indexCase3 = 0;
    int indexCase4 = 0;

    while(run){
        //User interactive menu
        cout<< "\nWelcome, what would you like to do?\n";
        cout<< "1. Add an animal to the aquarium\n";
        cout<< "2. Remove an animal from the aquarium\n";
        cout<< "3. Modify an animal\n";
        cout<< "4. Display an animal's profile\n";
        cout<< "5. Exit\n";
        cout<< "Enter choice: ";
        cin>> userChoice;
        cout<< "Your choice was " << userChoice << endl;

        switch(userChoice){
            //Case 1: add an animal
            case 1:

                cout<< "Enter animal type (Aquarium Animal or Fish): ";
                cin>> type;
                clearInputBuffer();
                cout << "Enter species: ";
                getline(cin, species);
                cout << "Enter habitat: ";
                getline(cin, habitat);
                cout << "Enter country of origin: ";
                getline(cin, country);
                cout << "Enter diet: ";
                getline(cin, diet);
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter age: ";
                cin >> age;
                clearInputBuffer();
                cout << "Enter DOB (MMDDYY): ";
                cin >> DOB;
                clearInputBuffer();
                cout << "Enter weight (kg): ";
                cin >> weight;
                clearInputBuffer();
                cout << "Enter height (cm): ";
                cin >> height;
                clearInputBuffer();
                cout << "Enter endangered status (1 for yes, 0 for no): ";
                cin >> isEndangered;
                clearInputBuffer();
                cout << "Enter temperature preference (Fahrenheit): ";
                cin >> temperaturePreference;
                clearInputBuffer();
                cout << "Enter lifespan (years): ";
                cin >> lifespan;
                clearInputBuffer();
                cout << "Enter nocturnal status (1 for yes, 0 for no): ";
                cin >> isNocturnal;
                clearInputBuffer();
                cout << "Enter color pattern: ";
                getline(cin, colorPattern);
                cout << "Enter animal ID: ";
                getline(cin, animalID);

                //Additional input for fish
                if(type == "Fish"){

                    cout << "Enter water type (freshwater or saltwater): ";
                    cin >> waterType;
                    cout << "Enter fin count: ";
                    cin >> finCount;
                    cout << "Enter scale type (smooth, rough, spiny): ";
                    cin >> scaleType;

                    animals.push_back(new Fish(species, habitat, country, diet, name, age, DOB, weight, height, isEndangered, temperaturePreference, lifespan, isNocturnal, colorPattern, animalID, waterType, finCount, scaleType));
                } else {
                    animals.push_back(new AquariumAnimal(species, habitat, country, diet, name, age, DOB, weight, height, isEndangered, temperaturePreference, lifespan, isNocturnal, colorPattern, animalID));
                }

                cout<< "Animal added!" << endl;
                break;
            //Case 2: Remove animal
            case 2:
                if(animals.empty()) {
                    cout<< "There are no animals in the aquarium to remove." << endl;
                    break;
                    
                } else{
                    cout<< "List of all animals in the aquarium: " << endl;
                    for(int i = 0; i < animals.size(); i++){
                        cout<< i+1 << ". " << animals[i]->getSpecies() << "- " << animals[i]-> getName() << endl;
                    }
                }
                

                cout<< "Enter index of animal to remove: ";
                cin>> indexCase2;
                indexCase2--;

                if (indexCase2 >= 0 && indexCase2 < animals.size()) {
                    delete animals[indexCase2];
                    // Remove the pointer from the vector
                    animals.erase(animals.begin() + indexCase2);
                    cout << "Animal was removed." << endl;
                } else {
                    cout << "Invalid index, try again." << endl;
                }
                break;
            //Case 3: Modify animal
            case 3: 
                if(animals.empty()) {
                    cout<< "There are no animals in the aquarium to remove." << endl;
                    break;
                }else{
                    cout<< "List of all animals in the aquarium: " << endl;
                    for(int i = 0; i < animals.size(); i++){
                        cout<< i+1 << ". " << animals[i]->getSpecies() << "- " << animals[i]-> getName() << endl;
                    }

                    cout<< "Enter index of animal you want to modify: ";
                    cin>> indexCase3;
                    indexCase3--;

                    if (indexCase3 >= 0 && indexCase3 < animals.size()) {
                        cout<< "current property of animal: " << endl;
                        cout << animals[indexCase3]->getAnimalProfile() << endl;

                        //Properties to modify menu
                        cout<< "What properties would you like to modify?" << endl;
                        cout << "1. Species\n";
                        cout << "2. Name\n";
                        cout << "3. Habitat\n";
                        cout<< "4. Diet\n";
                        cout<< "Enter Choice: ";
                        int choice;
                        cin>> choice;

                        switch(choice){
                            case 1: {
                                cout<< "Enter animal species: ";
                                string newSpecies;
                                cin >> newSpecies;
                                animals[indexCase3]->setSpecies(newSpecies);
                                break;
                            }
                            case 2:{
                                cout << "Enter new name: ";
                                string newName;
                                cin >> newName;
                                animals[indexCase3]->setName(newName);
                                break;
                            }
                            case 3:{
                                cout << "Enter new habitat: ";
                                string newHabitat;
                                cin >> newHabitat;
                                animals[indexCase3]->setHabitat(newHabitat);
                                break;
                            }
                            case 4:{
                                cout << "Enter new Diet: ";
                                string newDiet;
                                cin >> newDiet;
                                animals[indexCase3]->setDiet(newDiet);
                                break;
                            }
                            default:
                            cout << "Invalid option. No changes made." << endl;
                        }

                    }else {
                        cout << "Invalid index, try again." << endl;
                    }
                }
                break;
            //Case 4: Display a animal profile
            case 4: 
                if(animals.empty()) {
                    cout<< "There are no animals in the aquarium to remove." << endl;
                    break;
                }else{
                    cout<< "List of all animals in the aquarium: " << endl;

                    for(int i = 0; i < animals.size(); i++){
                        cout<< i+1 << ". " << animals[i]->getSpecies() << "- " << animals[i]-> getName() << endl;
                    }

                    cout<< "Enter the index of the animal whose profile you want to view: ";
                    cin>> indexCase4;
                    indexCase4--;

                    if (indexCase3 >= 0 && indexCase3 < animals.size()) {
                        cout<< "Displaying animal profile for:  " << animals[indexCase4]->getName() << " (" << animals[indexCase4]->getSpecies() << "):" << endl;
                        cout << animals[indexCase3]->getAnimalProfile() << endl;
                    }else{
                        cout << "Invalid index, try again." << endl;
                    }
                }
                break;
            case 5:
                run = false;
                cout<< "Ending... Goodbye!" << endl;
                break;

        }

    }

    return 0;
}

