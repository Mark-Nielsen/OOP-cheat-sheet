#include "OOP_Eksamen_Eksempler.h"

// ==================== Nyere C++ syntaks: auto, range, {}, [[nodiscard]] ====================

ModernSyntaxExample::ModernSyntaxExample()
    : value_{10}, values_{1, 2, 3, 4} {
}

int ModernSyntaxExample::getValue() const {
    return value_;
}

void ModernSyntaxExample::setValues(const std::vector<int>& values) {
    values_ = values;
}

void ModernSyntaxExample::printValues() const {
    for (auto number : values_) {
        std::cout << number << " ";
    }
    std::cout << "\n";
}

// ==================== Pointere ====================

PointerBox::PointerBox()
    : ptr_{nullptr} {
}

void PointerBox::setPointer(int* ptr) {
    ptr_ = ptr;
}

void PointerBox::printPointerValue() const {
    if (ptr_ != nullptr) {
        std::cout << *ptr_ << "\n";
    }
}

void PointerBox::changeValueThroughPointer(int newValue) {
    if (ptr_ != nullptr) {
        *ptr_ = newValue;
    }
}

// ==================== L-value referencer ====================

ReferenceChanger::ReferenceChanger() {
}

void ReferenceChanger::increase(int& number) const {
    number++;
}

void ReferenceChanger::swapValues(int& a, int& b) const {
    int temp = a;
    a = b;
    b = temp;
}

void ReferenceChanger::rename(std::string& name) const {
    name = "Nyt navn";
}

// ==================== const ====================

ConstStudent::ConstStudent(std::string name, int age)
    : name_{name}, age_{age} {
}

std::string ConstStudent::getName() const {
    return name_;
}

int ConstStudent::getAge() const {
    return age_;
}

void ConstStudent::setAge(int age) {
    age_ = age;
}

// ==================== Default copy constructor ====================

DefaultCopyPerson::DefaultCopyPerson(std::string name, int age)
    : name_{name}, age_{age} {
}

void DefaultCopyPerson::print() const {
    std::cout << name_ << " " << age_ << "\n";
}

void DefaultCopyPerson::setAge(int age) {
    age_ = age;
}

// ==================== Assignment ====================

AssignmentCar::AssignmentCar(std::string brand, int year)
    : brand_{brand}, year_{year} {
}

AssignmentCar& AssignmentCar::operator=(const AssignmentCar& other) {
    if (this != &other) {
        brand_ = other.brand_;
        year_ = other.year_;
    }

    return *this;
}

void AssignmentCar::print() const {
    std::cout << brand_ << " " << year_ << "\n";
}

// ==================== Composition ====================

Engine::Engine(int horsePower)
    : horsePower_{horsePower} {
}

void Engine::start() const {
    std::cout << "Motor starter med " << horsePower_ << " hk\n";
}

CompositionCar::CompositionCar(std::string brand, int horsePower)
    : brand_{brand}, engine_{horsePower} {
}

void CompositionCar::startCar() const {
    std::cout << brand_ << ": ";
    engine_.start();
}

// ==================== Association ====================

Course::Course(std::string title)
    : title_{title}, teacher_{nullptr} {
}

void Course::setTeacher(Teacher* teacher) {
    teacher_ = teacher;
}

void Course::printInfo() const {
    std::cout << title_;

    if (teacher_ != nullptr) {
        std::cout << " undervises af " << teacher_->getName();
    }

    std::cout << "\n";
}

Teacher::Teacher(std::string name)
    : name_{name} {
}

std::string Teacher::getName() const {
    return name_;
}

// ==================== Andre klasserelationer ====================

License::License(std::string type)
    : type_{type} {
}

std::string License::getType() const {
    return type_;
}

Driver::Driver(std::string name)
    : name_{name} {
}

void Driver::addLicense(const License& license) {
    licenses_.push_back(license);
}

void Driver::printLicenses() const {
    std::cout << name_ << " har kørekort: ";

    for (const auto& license : licenses_) {
        std::cout << license.getType() << " ";
    }

    std::cout << "\n";
}

// ==================== Static members ====================

int StaticCounter::count_ = 0;

StaticCounter::StaticCounter() {
    count_++;
}

int StaticCounter::getCount() {
    return count_;
}

// ==================== Errors ====================

ErrorExample::ErrorExample()
    : lastError_{""} {
}

bool ErrorExample::divide(int a, int b, int& result) const {
    if (b == 0) {
        return false;
    }

    result = a / b;
    return true;
}

bool ErrorExample::setAge(int age) {
    if (age < 0) {
        lastError_ = "Alder må ikke være negativ";
        return false;
    }

    lastError_ = "";
    return true;
}

std::string ErrorExample::getLastError() const {
    return lastError_;
}

// ==================== Exceptions ====================

BankAccount::BankAccount(double balance)
    : balance_{balance} {
}

void BankAccount::withdraw(double amount) {
    if (amount > balance_) {
        throw std::runtime_error("Der er ikke penge nok på kontoen");
    }

    balance_ -= amount;
}

double BankAccount::getBalance() const {
    return balance_;
}

// ==================== Debugging ====================

DebugExample::DebugExample() {
}

int DebugExample::calculateTotal(const std::vector<int>& numbers) const {
    int total = 0;

    for (int number : numbers) {
        total += number;
    }

    return total;
}

void DebugExample::printDebugInfo(const std::string& text) const {
    std::cout << "[DEBUG] " << text << "\n";
}

// ==================== Memory management ====================

MemoryManager::MemoryManager() {
}

void MemoryManager::useSmartPointer() const {
    std::unique_ptr<int> number = std::make_unique<int>(42);
    std::cout << *number << "\n";
}

void MemoryManager::useVectorMemory() const {
    std::vector<int> numbers{1, 2, 3};
    numbers.push_back(4);
    std::cout << numbers.size() << "\n";
}

// ==================== new/delete ====================

DynamicNumber::DynamicNumber() {
}

int* DynamicNumber::createNumber(int value) const {
    int* number = new int{value};
    return number;
}

void DynamicNumber::deleteNumber(int* number) const {
    delete number;
}

// ==================== Destructors ====================

DestructorExample::DestructorExample(std::string name)
    : name_{name} {
    std::cout << name_ << " er oprettet\n";
}

DestructorExample::~DestructorExample() {
    std::cout << name_ << " bliver slettet\n";
}

void DestructorExample::print() const {
    std::cout << name_ << "\n";
}

// ==================== this pointer ====================

ThisPointerExample::ThisPointerExample(std::string name)
    : name_{name} {
}

ThisPointerExample& ThisPointerExample::setName(std::string name) {
    this->name_ = name;
    return *this;
}

void ThisPointerExample::printThisAddress() const {
    std::cout << this << "\n";
}

// ==================== Object life cycle ====================

LifeCycleExample::LifeCycleExample()
    : name_{"Ukendt"} {
    std::cout << "Default constructor\n";
}

LifeCycleExample::LifeCycleExample(std::string name)
    : name_{name} {
    std::cout << "Constructor\n";
}

LifeCycleExample::LifeCycleExample(const LifeCycleExample& other)
    : name_{other.name_} {
    std::cout << "Copy constructor\n";
}

LifeCycleExample::~LifeCycleExample() {
    std::cout << "Destructor\n";
}

void LifeCycleExample::print() const {
    std::cout << name_ << "\n";
}

// ==================== Rule of 3: constructors, assignment, destructor ====================

RuleOfThreeArray::RuleOfThreeArray(int size)
    : size_{size}, data_{new int[size]} {
    for (int i = 0; i < size_; i++) {
        data_[i] = 0;
    }
}

RuleOfThreeArray::RuleOfThreeArray(const RuleOfThreeArray& other)
    : size_{other.size_}, data_{new int[other.size_]} {
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

RuleOfThreeArray& RuleOfThreeArray::operator=(const RuleOfThreeArray& other) {
    if (this != &other) {
        int* newData = new int[other.size_];

        for (int i = 0; i < other.size_; i++) {
            newData[i] = other.data_[i];
        }

        delete[] data_;
        size_ = other.size_;
        data_ = newData;
    }

    return *this;
}

RuleOfThreeArray::~RuleOfThreeArray() {
    delete[] data_;
}

void RuleOfThreeArray::setValue(int index, int value) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index findes ikke");
    }

    data_[index] = value;
}

int RuleOfThreeArray::getValue(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("Index findes ikke");
    }

    return data_[index];
}

int RuleOfThreeArray::getSize() const {
    return size_;
}

// ==================== Operator overload: binære og unære ====================

Vector2D::Vector2D(double x, double y)
    : x_{x}, y_{y} {
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D{x_ + other.x_, y_ + other.y_};
}

Vector2D Vector2D::operator-() const {
    return Vector2D{-x_, -y_};
}

bool Vector2D::operator==(const Vector2D& other) const {
    return x_ == other.x_ && y_ == other.y_;
}

void Vector2D::print() const {
    std::cout << "(" << x_ << ", " << y_ << ")\n";
}

// ==================== Friend functions ====================

SecretNumber::SecretNumber(int number)
    : number_{number} {
}

void printSecret(const SecretNumber& secret) {
    std::cout << secret.number_ << "\n";
}

bool isSameSecret(const SecretNumber& a, const SecretNumber& b) {
    return a.number_ == b.number_;
}

// ==================== STL ====================

StlVectorExample::StlVectorExample()
    : numbers_{} {
}

void StlVectorExample::addNumber(int number) {
    numbers_.push_back(number);
}

int StlVectorExample::getSum() const {
    int sum = 0;

    for (int number : numbers_) {
        sum += number;
    }

    return sum;
}

void StlVectorExample::printNumbers() const {
    for (int number : numbers_) {
        std::cout << number << " ";
    }

    std::cout << "\n";
}

// ==================== STL fortsat ====================

StlObjectCollection::StlObjectCollection()
    : students_{} {
}

void StlObjectCollection::addStudent(const ConstStudent& student) {
    students_.push_back(student);
}

void StlObjectCollection::printStudents() const {
    for (const auto& student : students_) {
        std::cout << student.getName() << " " << student.getAge() << "\n";
    }
}

int StlObjectCollection::getAmount() const {
    return static_cast<int>(students_.size());
}

// ==================== Inheritance + virtual metode med override ====================

Animal::Animal(std::string name)
    : name_{name} {
}

Animal::~Animal() {
}

std::string Animal::getName() const {
    return name_;
}

void Animal::eat() const {
    std::cout << name_ << " spiser\n";
}

void Animal::makeSound() const {
    std::cout << name_ << " laver en lyd\n";
}

Dog::Dog(std::string name)
    : Animal{name} {
}

void Dog::bark() const {
    std::cout << name_ << " siger vov\n";
}

void Dog::makeSound() const {
    std::cout << name_ << " siger vov\n";
}

Cat::Cat(std::string name)
    : Animal{name} {
}

void Cat::makeSound() const {
    std::cout << name_ << " siger miav\n";
}

void printAnimalSound(const Animal& animal) {
    animal.makeSound();
}

// ==================== Polymorfi + pure virtual metode / abstract class ====================

Shape::~Shape() {
}

Rectangle::Rectangle(double width, double height)
    : width_{width}, height_{height} {
}

double Rectangle::getArea() const {
    return width_ * height_;
}

void Rectangle::printType() const {
    std::cout << "Rektangel\n";
}

Circle::Circle(double radius)
    : radius_{radius} {
}

double Circle::getArea() const {
    return 3.14159 * radius_ * radius_;
}

void Circle::printType() const {
    std::cout << "Cirkel\n";
}

void printShapeInfo(const Shape& shape) {
    shape.printType();
    std::cout << "Areal: " << shape.getArea() << "\n";
}

// ==================== Virtual metode brugt med pointer/reference ====================

Employee::Employee(std::string name)
    : name_{name} {
}

Employee::~Employee() {
}

double Employee::calculatePay() const {
    return 0.0;
}

HourlyEmployee::HourlyEmployee(std::string name, double hours, double hourlyRate)
    : Employee{name}, hours_{hours}, hourlyRate_{hourlyRate} {
}

double HourlyEmployee::calculatePay() const {
    return hours_ * hourlyRate_;
}

FixedEmployee::FixedEmployee(std::string name, double monthlyPay)
    : Employee{name}, monthlyPay_{monthlyPay} {
}

double FixedEmployee::calculatePay() const {
    return monthlyPay_;
}

void printEmployeePay(const Employee& employee) {
    std::cout << "Løn: " << employee.calculatePay() << "\n";
}

// ==================== Streaming operator med friend function ====================

Person::Person(std::string name, int age)
    : name_{name}, age_{age} {
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name_ << " er " << person.age_ << " år";
    return os;
}

// ==================== Streaming operator uden friend function ====================

Point::Point(double x, double y)
    : x_{x}, y_{y} {
}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

// ==================== Streaming operator med STL vector ====================

Team::Team(std::string name)
    : name_{name}, players_{} {
}

void Team::addPlayer(const std::string& player) {
    players_.push_back(player);
}

std::string Team::getName() const {
    return name_;
}

const std::vector<std::string>& Team::getPlayers() const {
    return players_;
}

std::ostream& operator<<(std::ostream& os, const Team& team) {
    os << team.getName() << ": ";

    for (const auto& player : team.getPlayers()) {
        os << player << " ";
    }

    return os;
}

// ==================== Eksempel: syntax til forskellige STL containers ====================

ContainerExamples::ContainerExamples() {
}

// ==================== vector ====================

void ContainerExamples::vectorExample() const {
    std::vector<int> numbers{1, 2, 3};

    numbers.push_back(4);
    numbers.pop_back();

    numbers[0] = 10;
    numbers.at(1) = 20;

    std::cout << "Vector: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n";
}

// ==================== list ====================

void ContainerExamples::listExample() const {
    std::list<std::string> names{"Mark", "Anna"};

    names.push_back("Jonas");
    names.push_front("Ida");

    names.pop_back();
    names.pop_front();

    std::cout << "List: ";

    for (const std::string& name : names) {
        std::cout << name << " ";
    }

    std::cout << "\n";
}

// ==================== deque ====================

void ContainerExamples::dequeExample() const {
    std::deque<int> numbers{2, 3};

    numbers.push_back(4);
    numbers.push_front(1);

    numbers.pop_back();
    numbers.pop_front();

    std::cout << "Deque: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n";
}

// ==================== array ====================

void ContainerExamples::arrayExample() const {
    std::array<int, 3> numbers{10, 20, 30};

    numbers[0] = 100;
    numbers.at(1) = 200;

    std::cout << "Array: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n";
}

// ==================== set ====================

void ContainerExamples::setExample() const {
    std::set<int> numbers{3, 1, 2, 2};

    numbers.insert(4);
    numbers.erase(1);

    std::cout << "Set: ";

    for (int number : numbers) {
        std::cout << number << " ";
    }

    std::cout << "\n";

    if (numbers.find(3) != numbers.end()) {
        std::cout << "3 findes i set\n";
    }
}

// ==================== map ====================

void ContainerExamples::mapExample() const {
    std::map<std::string, int> ages;

    ages["Mark"] = 22;
    ages["Anna"] = 21;

    ages.insert({"Jonas", 24});
    ages.erase("Anna");

    std::cout << "Map: ";

    for (const auto& pair : ages) {
        std::cout << pair.first << "=" << pair.second << " ";
    }

    std::cout << "\n";

    if (ages.find("Mark") != ages.end()) {
        std::cout << "Mark findes i map\n";
    }
}

// ==================== unordered_map ====================

void ContainerExamples::unorderedMapExample() const {
    std::unordered_map<std::string, double> prices;

    prices["Milk"] = 12.5;
    prices["Bread"] = 20.0;

    prices.insert({"Apple", 4.5});
    prices.erase("Bread");

    std::cout << "Unordered map: ";

    for (const auto& pair : prices) {
        std::cout << pair.first << "=" << pair.second << " ";
    }

    std::cout << "\n";
}

// ==================== stack ====================

void ContainerExamples::stackExample() const {
    std::stack<int> numbers;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Stack top: " << numbers.top() << "\n";

    numbers.pop();

    std::cout << "Stack top efter pop: " << numbers.top() << "\n";
}

// ==================== queue ====================

void ContainerExamples::queueExample() const {
    std::queue<std::string> names;

    names.push("Mark");
    names.push("Anna");
    names.push("Jonas");

    std::cout << "Queue front: " << names.front() << "\n";
    std::cout << "Queue back: " << names.back() << "\n";

    names.pop();

    std::cout << "Queue front efter pop: " << names.front() << "\n";
}

// ==================== priority_queue ====================

void ContainerExamples::priorityQueueExample() const {
    std::priority_queue<int> numbers;

    numbers.push(10);
    numbers.push(50);
    numbers.push(20);

    std::cout << "Priority queue top: " << numbers.top() << "\n";

    numbers.pop();

    std::cout << "Priority queue top efter pop: " << numbers.top() << "\n";
}

// ==================== Hvad returneres hvornår ====================

LimitChecker::LimitChecker(double lowerLimit, double upperLimit)
    : lowerLimit_{lowerLimit}, upperLimit_{upperLimit} {
}

bool LimitChecker::isBelowLimit(double value) const {
    // Returnerer true hvis value er mindre end upperLimit_
    // Ellers returneres false
    return value < upperLimit_;
}

bool LimitChecker::isAboveLimit(double value) const {
    // Returnerer true hvis value er større end upperLimit_
    // Ellers returneres false
    return value > upperLimit_;
}

bool LimitChecker::isInsideLimits(double value) const {
    // Returnerer true hvis value er større end eller lig lowerLimit_
    // OG mindre end eller lig upperLimit_
    // Ellers returneres false
    return value >= lowerLimit_ && value <= upperLimit_;
}

// ==================== Eksempel 1: Exception ved division ====================

Divider::Divider() {
}

double Divider::divide(double a, double b) const {
    // Hvis b er 0, kan vi ikke dividere
    // Derfor kastes en exception
    if (b == 0) {
        throw std::runtime_error("Du kan ikke dividere med 0");
    }

    return a / b;
}

// ==================== Eksempel 2: Exception ved ugyldig alder ====================

PersonValidator::PersonValidator()
    : age_{0} {
}

void PersonValidator::setAge(int age) {
    // Hvis alder er negativ, kastes en exception
    if (age < 0) {
        throw std::invalid_argument("Alder må ikke være negativ");
    }

    age_ = age;
}

int PersonValidator::getAge() const {
    return age_;
}

// ==================== Eksempel 3: Exception ved ugyldigt index ====================

NumberList::NumberList()
    : numbers_{} {
}

void NumberList::addNumber(int number) {
    numbers_.push_back(number);
}

int NumberList::getNumberAt(int index) const {
    // Hvis index er uden for listen, kastes en exception
    if (index < 0 || index >= static_cast<int>(numbers_.size())) {
        throw std::out_of_range("Index findes ikke");
    }

    return numbers_[index];
}

// ==================== try & catch ====================

void tryCatchExample() {
    try {
        Divider divider;
        std::cout << divider.divide(10, 2) << "\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }
}

// ==================== to_string uden slut komma ====================

SimpleBox::SimpleBox(int sideLength)
    : sideLength_{sideLength} {
}

int SimpleBox::volume() const {
    return sideLength_ * sideLength_ * sideLength_;
}

void Boxes::addBox(const SimpleBox& box) {
    boxes_.push_back(box);
}

std::string Boxes::to_string() const {
    std::ostringstream result;

    for (std::size_t i = 0; i < boxes_.size(); i++) {
        if (i > 0) {
            result << ",";
        }

        result << boxes_[i].volume();
    }

    return result.str();
}

// ==================== explicit constructor + default argument ====================

TemperatureValue::TemperatureValue(double celsius)
    : celsius_{celsius} {
}

double TemperatureValue::toCelsius() const {
    return celsius_;
}

double TemperatureValue::toFahrenheit() const {
    return celsius_ * 9.0 / 5.0 + 32.0;
}

bool TemperatureValue::operator<(const TemperatureValue& right) const {
    return celsius_ < right.celsius_;
}

bool TemperatureValue::operator>(const TemperatureValue& right) const {
    return celsius_ > right.celsius_;
}

TemperatureValue TemperatureValue::operator+(const TemperatureValue& right) const {
    return TemperatureValue{celsius_ + right.celsius_};
}

TemperatureValue TemperatureValue::operator*(double factor) const {
    return TemperatureValue{celsius_ * factor};
}

TemperatureValue TemperatureValue::operator/(double factor) const {
    return TemperatureValue{celsius_ / factor};
}

std::ostream& operator<<(std::ostream& os, const TemperatureValue& temperature) {
    os << temperature.toCelsius() << " C";
    return os;
}

// ==================== inline static member ====================

CapacitorExample::CapacitorExample(double farad)
    : farad_{farad < lowerBound_ ? lowerBound_ : farad} {
}

double CapacitorExample::getFarad() const {
    return farad_;
}

std::ostream& operator<<(std::ostream& os, const CapacitorExample& capacitor) {
    os << capacitor.farad_ << " F";
    return os;
}

CapacitorExample operator|(const CapacitorExample& left, const CapacitorExample& right) {
    return CapacitorExample{left.farad_ + right.farad_};
}

CapacitorExample operator&(const CapacitorExample& left, const CapacitorExample& right) {
    return CapacitorExample{1.0 / (1.0 / left.farad_ + 1.0 / right.farad_)};
}

// ==================== Flere operator overloads: *, &&, <, >, / ====================

Matrix2x2::Matrix2x2(double k11, double k12, double k21, double k22)
    : k11_{k11}, k12_{k12}, k21_{k21}, k22_{k22} {
}

Matrix2x2 operator*(const Matrix2x2& left, const Matrix2x2& right) {
    return Matrix2x2{
        left.k11_ * right.k11_ + left.k12_ * right.k21_,
        left.k11_ * right.k12_ + left.k12_ * right.k22_,
        left.k21_ * right.k11_ + left.k22_ * right.k21_,
        left.k21_ * right.k12_ + left.k22_ * right.k22_
    };
}

std::ostream& operator<<(std::ostream& os, const Matrix2x2& matrix) {
    os << "[[" << matrix.k11_ << ", " << matrix.k12_ << "], ["
       << matrix.k21_ << ", " << matrix.k22_ << "]]";
    return os;
}

CircleIntersectExample::CircleIntersectExample(Point center, double radius)
    : center_{center}, radius_{radius} {
}

CircleIntersectExample CircleIntersectExample::operator*(double factor) const {
    return CircleIntersectExample{center_, radius_ * factor};
}

bool operator&&(const CircleIntersectExample& left, const CircleIntersectExample& right) {
    const double dx = left.center_.getX() - right.center_.getX();
    const double dy = left.center_.getY() - right.center_.getY();
    const double distance = std::sqrt(dx * dx + dy * dy);

    return distance <= left.radius_ + right.radius_;
}

std::ostream& operator<<(std::ostream& os, const CircleIntersectExample& circle) {
    os << "Center: " << circle.center_ << ", radius: " << circle.radius_;
    return os;
}

// ==================== operator() function call ====================

Polynomial::Polynomial(const std::vector<double>& coefficients)
    : coefficients_{coefficients.empty() ? std::vector<double>{0.0} : coefficients} {
}

double Polynomial::operator()(double value) const {
    double result = 0;
    double power = 1;

    for (double coefficient : coefficients_) {
        result += coefficient * power;
        power *= value;
    }

    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    const std::size_t maxSize = std::max(coefficients_.size(), other.coefficients_.size());
    std::vector<double> newCoefficients;

    for (std::size_t i = 0; i < maxSize; i++) {
        const double left = i < coefficients_.size() ? coefficients_[i] : 0.0;
        const double right = i < other.coefficients_.size() ? other.coefficients_[i] : 0.0;
        newCoefficients.push_back(left + right);
    }

    return Polynomial{newCoefficients};
}

std::size_t Polynomial::order() const {
    return coefficients_.size() - 1;
}

std::size_t Polynomial::size() const {
    return coefficients_.size();
}

std::string Polynomial::toString() const {
    std::ostringstream result;

    for (std::size_t i = 0; i < coefficients_.size(); i++) {
        if (i > 0) {
            result << " + ";
        }

        result << coefficients_[i] << "*x^" << i;
    }

    return result.str();
}

// ==================== std::pair, emplace_back og private hjælpefunktion ====================

LocationExample::LocationExample(double longitude, double latitude)
    : longitude{longitude}, latitude{latitude} {
}

bool LocationExample::operator==(const LocationExample& other) const {
    return longitude == other.longitude && latitude == other.latitude;
}

// ==================== Template method pattern med protected pure virtual methods ====================

DataCollector::~DataCollector() {
}

void DataCollector::receive(double value) {
    collect(value);
}

std::string DataCollector::print() const {
    const std::vector<double> values = prepare();
    std::ostringstream result;

    for (double value : values) {
        if (filter(value)) {
            result << format(value);
        }
    }

    result << "\n";
    return result.str();
}

void UniqueSortedCollector::collect(double value) {
    data_.insert(value);
}

std::vector<double> UniqueSortedCollector::prepare() const {
    std::vector<double> result;

    for (double value : data_) {
        result.push_back(value);
    }

    return result;
}

CsvUniqueSortedCollector::CsvUniqueSortedCollector(double upperLimit)
    : upperLimit_{upperLimit} {
}

bool CsvUniqueSortedCollector::filter(double value) const {
    return value < upperLimit_;
}

std::string CsvUniqueSortedCollector::format(double value) const {
    return std::to_string(value) + ",";
}

JsonCollector::JsonCollector(std::string valueName, double lowerLimit, double upperLimit)
    : valueName_{valueName}, range_{lowerLimit, upperLimit}, data_{} {
}

void JsonCollector::collect(double value) {
    data_.push_back(value);
}

std::vector<double> JsonCollector::prepare() const {
    return data_;
}

bool JsonCollector::filter(double value) const {
    return value >= range_.first && value <= range_.second;
}

std::string JsonCollector::format(double value) const {
    std::ostringstream result;
    result << "{\"" << valueName_ << "\":" << value << "}";
    return result.str();
}

// ==================== Vector af base-class pointers ====================

Loan::Loan(std::string name, double principal, double interestRate, unsigned int terms)
    : name_{name}, principal_{principal}, interestRate_{interestRate}, terms_{terms} {
}

Loan::~Loan() {
}

std::string Loan::getPaymentScheme() const {
    std::ostringstream result;

    for (unsigned int term = 1; term <= terms_; term++) {
        result << name_ << " termin " << term << ": " << getPayment(term) << "\n";
    }

    result << "Total: " << getTotalPayment() << "\n";
    return result.str();
}

double Loan::getTotalPayment() const {
    double total = 0;

    for (unsigned int term = 1; term <= terms_; term++) {
        total += getPayment(term);
    }

    return total;
}

double Loan::getPrincipal() const {
    return principal_;
}

double Loan::getRate() const {
    return interestRate_;
}

unsigned int Loan::getTerms() const {
    return terms_;
}

std::string Loan::getName() const {
    return name_;
}

SerialLoan::SerialLoan(std::string name, double principal, double interestRate, unsigned int terms)
    : Loan{name, principal, interestRate, terms} {
}

double SerialLoan::getPayment(unsigned int term) const {
    if (term < 1 || term > getTerms()) {
        throw std::invalid_argument("Ugyldig termin");
    }

    const double principalPayment = getPrincipal() / getTerms();
    const double restDebt = getPrincipal() - principalPayment * (term - 1);
    return principalPayment + restDebt * getRate();
}

AnnuityLoan::AnnuityLoan(std::string name, double principal, double interestRate, unsigned int terms)
    : Loan{name, principal, interestRate, terms},
      payment_{calculatePayment(principal, interestRate, terms)} {
}

double AnnuityLoan::getPayment(unsigned int term) const {
    if (term < 1 || term > getTerms()) {
        throw std::invalid_argument("Ugyldig termin");
    }

    return payment_;
}

double AnnuityLoan::calculatePayment(double principal, double interestRate, unsigned int terms) {
    return principal * interestRate * std::pow(1.0 + interestRate, terms) /
           (std::pow(1.0 + interestRate, terms) - 1.0);
}

void Account::addLoan(Loan* loan) {
    loans_.push_back(loan);
}

std::string Account::allSchemes() const {
    std::ostringstream result;

    for (const auto& loan : loans_) {
        result << loan->getPaymentScheme() << "\n";
    }

    return result.str();
}

// ==================== = default special members ====================

GainAmplifier::GainAmplifier(double gain)
    : gain_{gain} {
}

void GainAmplifier::amplify(double& value) const {
    value *= gain_;
}

// ==================== Kædede metodekald med return *this ====================

LowPassFilter::LowPassFilter(double threshold)
    : threshold_{threshold} {
}

double LowPassFilter::transform(double value) const {
    if (value > threshold_) {
        return threshold_;
    }

    return value;
}

HighPassFilter::HighPassFilter(double threshold)
    : threshold_{threshold} {
}

double HighPassFilter::transform(double value) const {
    if (value < threshold_) {
        return threshold_;
    }

    return value;
}

void DataSequence::add(double value) {
    data_.push_back(value);
}

const std::vector<double>& DataSequence::getData() const {
    return data_;
}

DataSequence& DataSequence::applyFilter(const FilterTransform& filter) {
    for (double& value : data_) {
        value = filter.transform(value);
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const DataSequence& dataSequence) {
    for (double value : dataSequence.data_) {
        os << value << " ";
    }

    return os;
}

// ==================== list::sort i egen priority queue ====================

PriorityPerson::PriorityPerson(std::string name, int priority)
    : name_{name}, priority_{priority} {
}

bool operator<(const PriorityPerson& left, const PriorityPerson& right) {
    return left.priority_ < right.priority_;
}

std::ostream& operator<<(std::ostream& os, const PriorityPerson& person) {
    os << person.name_ << " " << person.priority_;
    return os;
}

// ==================== Mutable string reference + polymorf behandling ====================

void ToUpperCaseProcessor::process(std::string& text) const {
    for (char& letter : text) {
        letter = static_cast<char>(std::toupper(static_cast<unsigned char>(letter)));
    }
}

RemoveCharProcessor::RemoveCharProcessor(char character)
    : character_{character} {
}

void RemoveCharProcessor::process(std::string& text) const {
    std::string result;

    for (char letter : text) {
        if (letter != character_) {
            result.push_back(letter);
        }
    }

    text = result;
}

Document::Document(std::string text)
    : processors_{}, text_{text} {
}

void Document::add(StringProcessor* processor) {
    processors_.push_back(processor);
}

void Document::process() {
    for (const auto& processor : processors_) {
        processor->process(text_);
    }
}

std::ostream& operator<<(std::ostream& os, const Document& document) {
    os << document.text_;
    return os;
}

// ==================== Valuta conversion + friend operator== ====================

Currency::Currency(std::string symbol, double factor)
    : symbol_{symbol}, factor_{factor} {
}

double Currency::toStandardCurrency(double amount) const {
    return amount * factor_;
}

double Currency::fromStandardCurrency(double amount) const {
    return amount / factor_;
}

std::string Currency::getSymbol() const {
    return symbol_;
}

Amount::Amount(double amount, Currency currency)
    : amount_{amount}, currency_{currency} {
}

Amount Amount::operator+(const Amount& right) const {
    const double leftStandard = currency_.toStandardCurrency(amount_);
    const double rightStandard = right.currency_.toStandardCurrency(right.amount_);
    const double sumStandard = leftStandard + rightStandard;

    return Amount{currency_.fromStandardCurrency(sumStandard), currency_};
}

std::string Amount::toString() const {
    return std::to_string(amount_) + " " + currency_.getSymbol();
}

bool operator==(const Amount& left, const Amount& right) {
    const double leftStandard = left.currency_.toStandardCurrency(left.amount_);
    const double rightStandard = right.currency_.toStandardCurrency(right.amount_);

    return std::abs(leftStandard - rightStandard) < 0.001;
}

#include "IteratorEksempler.h"

// ==================== Iterator med vector ====================

VectorIteratorExample::VectorIteratorExample()
    : numbers_{} {
}

void VectorIteratorExample::addNumber(int number) {
    numbers_.push_back(number);
}

void VectorIteratorExample::printWithIterator() const {
    // begin() peger på første element
    // end() peger lige efter sidste element
    for (auto it = numbers_.begin(); it != numbers_.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}

void VectorIteratorExample::changeWithIterator() {
    // *it giver adgang til selve værdien
    for (auto it = numbers_.begin(); it != numbers_.end(); ++it) {
        *it = *it * 2;
    }
}

// ==================== Const iterator med vector ====================

ConstIteratorExample::ConstIteratorExample()
    : names_{} {
}

void ConstIteratorExample::addName(const std::string& name) {
    names_.push_back(name);
}

void ConstIteratorExample::printWithConstIterator() const {
    // cbegin() og cend() bruges når værdierne ikke skal ændres
    for (auto it = names_.cbegin(); it != names_.cend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}

// ==================== Iterator med map ====================

MapIteratorExample::MapIteratorExample()
    : grades_{} {
}

void MapIteratorExample::addGrade(const std::string& name, int grade) {
    grades_[name] = grade;
}

void MapIteratorExample::printGrades() const {
    // Ved map er it->first key
    // Ved map er it->second value
    for (auto it = grades_.cbegin(); it != grades_.cend(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

void MapIteratorExample::increaseGrades() {
    // second kan ændres, fordi det er value
    for (auto it = grades_.begin(); it != grades_.end(); ++it) {
        it->second = it->second + 1;
    }
}

// ==================== Iterator med find ====================

FindIteratorExample::FindIteratorExample()
    : numbers_{} {
}

void FindIteratorExample::addNumber(int number) {
    numbers_.push_back(number);
}

bool FindIteratorExample::containsNumber(int number) const {
    // std::find returnerer en iterator til elementet hvis det findes
    // Hvis det ikke findes, returneres numbers_.end()
    auto it = std::find(numbers_.begin(), numbers_.end(), number);

    return it != numbers_.end();
}

// ==================== Iterator med erase ====================

EraseIteratorExample::EraseIteratorExample()
    : numbers_{} {
}

void EraseIteratorExample::addNumber(int number) {
    numbers_.push_back(number);
}

void EraseIteratorExample::removeNumber(int number) {
    // Iterator bruges til at finde elementet
    auto it = std::find(numbers_.begin(), numbers_.end(), number);

    // Hvis iteratoren ikke er end(), findes elementet
    if (it != numbers_.end()) {
        numbers_.erase(it);
    }
}

void EraseIteratorExample::printNumbers() const {
    for (auto it = numbers_.cbegin(); it != numbers_.cend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}