#ifndef OOP_EKSAMEN_EKSEMPLER_H
#define OOP_EKSAMEN_EKSEMPLER_H

#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <utility>
#include <cctype>

// ==================== Nyere C++ syntaks: auto, range, {}, [[nodiscard]] ====================

class ModernSyntaxExample {
public:
    ModernSyntaxExample();

    [[nodiscard]] int getValue() const;
    void setValues(const std::vector<int>& values);
    void printValues() const;

private:
    int value_;
    std::vector<int> values_;
};

// ==================== Pointere ====================

class PointerBox {
public:
    PointerBox();

    void setPointer(int* ptr);
    void printPointerValue() const;
    void changeValueThroughPointer(int newValue);

private:
    int* ptr_;
};

// ==================== L-value referencer ====================

class ReferenceChanger {
public:
    ReferenceChanger();

    void increase(int& number) const;
    void swapValues(int& a, int& b) const;
    void rename(std::string& name) const;
};

// ==================== const ====================

class ConstStudent {
public:
    ConstStudent(std::string name, int age);

    std::string getName() const;
    int getAge() const;
    void setAge(int age);

private:
    std::string name_;
    int age_;
};

// ==================== Default copy constructor ====================

class DefaultCopyPerson {
public:
    DefaultCopyPerson(std::string name, int age);

    void print() const;
    void setAge(int age);

private:
    std::string name_;
    int age_;
};

// ==================== Assignment ====================

class AssignmentCar {
public:
    AssignmentCar(std::string brand, int year);

    AssignmentCar& operator=(const AssignmentCar& other);
    void print() const;

private:
    std::string brand_;
    int year_;
};

// ==================== Composition ====================

class Engine {
public:
    Engine(int horsePower);

    void start() const;

private:
    int horsePower_;
};

class CompositionCar {
public:
    CompositionCar(std::string brand, int horsePower);

    void startCar() const;

private:
    std::string brand_;
    Engine engine_;
};

// ==================== Association ====================

class Teacher;

class Course {
public:
    Course(std::string title);

    void setTeacher(Teacher* teacher);
    void printInfo() const;

private:
    std::string title_;
    Teacher* teacher_;
};

class Teacher {
public:
    Teacher(std::string name);

    std::string getName() const;

private:
    std::string name_;
};

// ==================== Andre klasserelationer ====================

class License {
public:
    License(std::string type);

    std::string getType() const;

private:
    std::string type_;
};

class Driver {
public:
    Driver(std::string name);

    void addLicense(const License& license);
    void printLicenses() const;

private:
    std::string name_;
    std::vector<License> licenses_;
};

// ==================== Static members ====================

class StaticCounter {
public:
    StaticCounter();

    static int getCount();

private:
    static int count_;
};

// ==================== Errors ====================

class ErrorExample {
public:
    ErrorExample();

    bool divide(int a, int b, int& result) const;
    bool setAge(int age);
    std::string getLastError() const;

private:
    std::string lastError_;
};

// ==================== Exceptions ====================

class BankAccount {
public:
    BankAccount(double balance);

    void withdraw(double amount);
    double getBalance() const;

private:
    double balance_;
};

// ==================== Debugging ====================

class DebugExample {
public:
    DebugExample();

    int calculateTotal(const std::vector<int>& numbers) const;
    void printDebugInfo(const std::string& text) const;
};

// ==================== Memory management ====================

class MemoryManager {
public:
    MemoryManager();

    void useSmartPointer() const;
    void useVectorMemory() const;
};

// ==================== new/delete ====================

class DynamicNumber {
public:
    DynamicNumber();

    int* createNumber(int value) const;
    void deleteNumber(int* number) const;
};

// ==================== Destructors ====================

class DestructorExample {
public:
    DestructorExample(std::string name);
    ~DestructorExample();

    void print() const;

private:
    std::string name_;
};

// ==================== this pointer ====================

class ThisPointerExample {
public:
    ThisPointerExample(std::string name);

    ThisPointerExample& setName(std::string name);
    void printThisAddress() const;

private:
    std::string name_;
};

// ==================== Object life cycle ====================

class LifeCycleExample {
public:
    LifeCycleExample();
    LifeCycleExample(std::string name);
    LifeCycleExample(const LifeCycleExample& other);
    ~LifeCycleExample();

    void print() const;

private:
    std::string name_;
};

// ==================== Rule of 3: constructors, assignment, destructor ====================

class RuleOfThreeArray {
public:
    RuleOfThreeArray(int size);
    RuleOfThreeArray(const RuleOfThreeArray& other);
    RuleOfThreeArray& operator=(const RuleOfThreeArray& other);
    ~RuleOfThreeArray();

    void setValue(int index, int value);
    int getValue(int index) const;
    int getSize() const;

private:
    int size_;
    int* data_;
};

// ==================== Operator overload: binære og unære ====================

class Vector2D {
public:
    Vector2D(double x, double y);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-() const;
    bool operator==(const Vector2D& other) const;
    void print() const;

private:
    double x_;
    double y_;
};

// ==================== Friend functions ====================

class SecretNumber {
public:
    SecretNumber(int number);

    friend void printSecret(const SecretNumber& secret);
    friend bool isSameSecret(const SecretNumber& a, const SecretNumber& b);

private:
    int number_;
};

// ==================== Template function ====================

// Template funktioner skal normalt ligge i header-filen.
template <typename T>
T getLargest(T a, T b) {
    if (a > b) {
        return a;
    }

    return b;
}

template <typename T>
void printTwice(const T& value) {
    std::cout << value << " " << value << "\n";
}

// ==================== Template class ====================

// Template klasser skal normalt ligge i header-filen.
template <typename T>
class StorageBox {
public:
    StorageBox(T value)
        : value_{value} {
    }

    T getValue() const {
        return value_;
    }

    void setValue(T value) {
        value_ = value;
    }

private:
    T value_;
};

// ==================== Templates fortsat ====================

template <typename T>
class PairBox {
public:
    PairBox(T first, T second)
        : first_{first}, second_{second} {
    }

    T getFirst() const {
        return first_;
    }

    T getSecond() const {
        return second_;
    }

    T getLargest() const {
        if (first_ > second_) {
            return first_;
        }

        return second_;
    }

private:
    T first_;
    T second_;
};

// ==================== Template klasse metoder uden for klasse, ====================
template <typename T>
class PairBoxTemplate {
public:
    PairBoxTemplate(T first, T second);

    T getFirst() const;
    T getSecond() const;
    T getLargest() const;

private:
    T first_;
    T second_;
};

template <typename T>
PairBoxTemplate<T>::PairBoxTemplate(T first, T second)
    : first_{first}, second_{second}
{
}

template <typename T>
T PairBoxTemplate<T>::getFirst() const {
    return first_;
}

template <typename T>
T PairBoxTemplate<T>::getSecond() const {
    return second_;
}

template <typename T>
T PairBoxTemplate<T>::getLargest() const {
    if (first_ > second_) {
        return first_;
    }

    return second_;
}

// ==================== Ekstre template eksempel ====================
template <typename T>
class PolynomialTemplate
{
public:
    PolynomialTemplate(const std::vector<T>& coefficients);
    T operator()(T value) const;
    PolynomialTemplate operator+(const PolynomialTemplate& other) const;
    size_t order() const;
    size_t size() const;
    std::string toString() const;

private:
    std::vector<T> coefficients_;
};

template <typename T>
PolynomialTemplate<T>::PolynomialTemplate(const std::vector<T>& coefficients)
    : coefficients_(coefficients)
{
}

template <typename T>
T PolynomialTemplate<T>::operator()(T value) const
{
    T result = T();
    T power = T(1);
    for (size_t i = 0; i < coefficients_.size(); ++i)
    {
        result += coefficients_[i] * power;
        power *= value;
    }
    return result;
}

template <typename T>
PolynomialTemplate<T> PolynomialTemplate<T>::operator+(const PolynomialTemplate<T>& other) const
{
    size_t maxSize = std::max(coefficients_.size(), other.coefficients_.size());
    std::vector<T> result(maxSize, T());

    for (size_t i = 0; i < coefficients_.size(); ++i)
    {
        result[i] += coefficients_[i];
    }
    for (size_t i = 0; i < other.coefficients_.size(); ++i)
    {
        result[i] += other.coefficients_[i];
    }

    return PolynomialTemplate<T>(result);
}

template <typename T>
size_t PolynomialTemplate<T>::order() const
{
    return coefficients_.size() - 1;
}

template <typename T>
size_t PolynomialTemplate<T>::size() const
{
    return coefficients_.size();
}

template <typename T>
std::string PolynomialTemplate<T>::toString() const
{
    std::ostringstream oss;
    for (size_t i = 0; i < coefficients_.size(); ++i)
    {
        if (i > 0)
        {
            oss << " + ";
        }
        oss << coefficients_[i] << "x^" << i;
    }
    return oss.str();
}

// ==================== STL ====================

class StlVectorExample {
public:
    StlVectorExample();

    void addNumber(int number);
    int getSum() const;
    void printNumbers() const;

private:
    std::vector<int> numbers_;
};

// ==================== STL fortsat ====================

class StlObjectCollection {
public:
    StlObjectCollection();

    void addStudent(const ConstStudent& student);
    void printStudents() const;
    int getAmount() const;

private:
    std::vector<ConstStudent> students_;
};

// ==================== Inheritance + virtual metode med override ====================

class Animal {
public:
    Animal(std::string name);
    virtual ~Animal();

    std::string getName() const;
    void eat() const;
    virtual void makeSound() const;

protected:
    std::string name_;
};

class Dog : public Animal {
public:
    Dog(std::string name);

    void bark() const;
    void makeSound() const override;
};

class Cat : public Animal {
public:
    Cat(std::string name);

    void makeSound() const override;
};

void printAnimalSound(const Animal& animal);

// ==================== Polymorfi + pure virtual metode / abstract class ====================

class Shape {
public:
    virtual ~Shape();

    virtual double getArea() const = 0;
    virtual void printType() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);

    double getArea() const override;
    void printType() const override;

private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius);

    double getArea() const override;
    void printType() const override;

private:
    double radius_;
};

void printShapeInfo(const Shape& shape);

// ==================== Virtual metode brugt med pointer/reference ====================

class Employee {
public:
    Employee(std::string name);
    virtual ~Employee();

    virtual double calculatePay() const;

protected:
    std::string name_;
};

class HourlyEmployee : public Employee {
public:
    HourlyEmployee(std::string name, double hours, double hourlyRate);

    double calculatePay() const override;

private:
    double hours_;
    double hourlyRate_;
};

class FixedEmployee : public Employee {
public:
    FixedEmployee(std::string name, double monthlyPay);

    double calculatePay() const override;

private:
    double monthlyPay_;
};

void printEmployeePay(const Employee& employee);

// ==================== Streaming operator med friend function ====================

class Person {
public:
    Person(std::string name, int age);

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
    std::string name_;
    int age_;
};

// ==================== Streaming operator uden friend function ====================

class Point {
public:
    Point(double x, double y);

    double getX() const;
    double getY() const;

private:
    double x_;
    double y_;
};

std::ostream& operator<<(std::ostream& os, const Point& point);

// ==================== Streaming operator med STL vector ====================

class Team {
public:
    Team(std::string name);

    void addPlayer(const std::string& player);
    std::string getName() const;
    const std::vector<std::string>& getPlayers() const;

private:
    std::string name_;
    std::vector<std::string> players_;
};

std::ostream& operator<<(std::ostream& os, const Team& team);

// ==================== Eksempel: syntax til forskellige STL containers ====================

class ContainerExamples {
public:
    ContainerExamples();

    void vectorExample() const;
    void listExample() const;
    void dequeExample() const;
    void arrayExample() const;
    void setExample() const;
    void mapExample() const;
    void unorderedMapExample() const;
    void stackExample() const;
    void queueExample() const;
    void priorityQueueExample() const;
};

// ==================== Hvad returneres hvornår ====================

class LimitChecker {
public:
    LimitChecker(double lowerLimit, double upperLimit);

    bool isBelowLimit(double value) const;
    bool isAboveLimit(double value) const;
    bool isInsideLimits(double value) const;

private:
    double lowerLimit_;
    double upperLimit_;
};

// ==================== Eksempel 1: Exception ved division ====================

class Divider {
public:
    Divider();

    double divide(double a, double b) const;
};

// ==================== Eksempel 2: Exception ved ugyldig alder ====================

class PersonValidator {
public:
    PersonValidator();

    void setAge(int age);
    int getAge() const;

private:
    int age_;
};

// ==================== Eksempel 3: Exception ved ugyldigt index ====================

class NumberList {
public:
    NumberList();

    void addNumber(int number);
    int getNumberAt(int index) const;

private:
    std::vector<int> numbers_;
};

void tryCatchExample();

// ==================== to_string uden slut komma ====================

class SimpleBox {
public:
    explicit SimpleBox(int sideLength);

    int volume() const;

private:
    int sideLength_;
};

class Boxes {
public:
    void addBox(const SimpleBox& box);
    std::string to_string() const;

private:
    std::vector<SimpleBox> boxes_;
};

// ==================== explicit constructor + default argument ====================

class TemperatureValue {
public:
    explicit TemperatureValue(double celsius = 0.0);

    [[nodiscard]] double toCelsius() const;
    [[nodiscard]] double toFahrenheit() const;

    bool operator<(const TemperatureValue& right) const;
    bool operator>(const TemperatureValue& right) const;
    TemperatureValue operator+(const TemperatureValue& right) const;
    TemperatureValue operator*(double factor) const;
    TemperatureValue operator/(double factor) const;

private:
    double celsius_;
};

std::ostream& operator<<(std::ostream& os, const TemperatureValue& temperature);

// ==================== inline static member ====================

class CapacitorExample {
public:
    explicit CapacitorExample(double farad);

    double getFarad() const;

    friend std::ostream& operator<<(std::ostream& os, const CapacitorExample& capacitor);
    friend CapacitorExample operator|(const CapacitorExample& left, const CapacitorExample& right);
    friend CapacitorExample operator&(const CapacitorExample& left, const CapacitorExample& right);

private:
    double farad_;
    inline static double lowerBound_ = 1E-10;
};

// ==================== Flere operator overloads: *, &&, <, >, / ====================

class Matrix2x2 {
public:
    Matrix2x2(double k11 = 1, double k12 = 0, double k21 = 0, double k22 = 1);

    friend Matrix2x2 operator*(const Matrix2x2& left, const Matrix2x2& right);
    friend std::ostream& operator<<(std::ostream& os, const Matrix2x2& matrix);

private:
    double k11_;
    double k12_;
    double k21_;
    double k22_;
};

class CircleIntersectExample {
public:
    CircleIntersectExample(Point center, double radius);

    CircleIntersectExample operator*(double factor) const;

    friend bool operator&&(const CircleIntersectExample& left, const CircleIntersectExample& right);
    friend std::ostream& operator<<(std::ostream& os, const CircleIntersectExample& circle);

private:
    Point center_;
    double radius_;
};

// ==================== operator() function call ====================

class Polynomial {
public:
    explicit Polynomial(const std::vector<double>& coefficients);

    double operator()(double value) const;
    Polynomial operator+(const Polynomial& other) const;
    std::size_t order() const;
    std::size_t size() const;
    std::string toString() const;

private:
    std::vector<double> coefficients_;
};

// ==================== Template class med operator() ====================

template <typename T>
class PolynomialTemplate {
public:
    explicit PolynomialTemplate(const std::vector<T>& coefficients)
        : coefficients_{coefficients.empty() ? std::vector<T>{T{0}} : coefficients} {
    }

    T operator()(T value) const {
        T result{0};
        T power{1};

        for (const auto& coefficient : coefficients_) {
            result = result + coefficient * power;
            power = power * value;
        }

        return result;
    }

    PolynomialTemplate operator+(const PolynomialTemplate& other) const {
        const std::size_t maxSize = std::max(coefficients_.size(), other.coefficients_.size());
        std::vector<T> newCoefficients;

        for (std::size_t i = 0; i < maxSize; i++) {
            const T left = i < coefficients_.size() ? coefficients_[i] : T{0};
            const T right = i < other.coefficients_.size() ? other.coefficients_[i] : T{0};
            newCoefficients.push_back(left + right);
        }

        return PolynomialTemplate{newCoefficients};
    }

    std::size_t size() const {
        return coefficients_.size();
    }

    std::string toString() const {
        std::ostringstream result;

        for (std::size_t i = 0; i < coefficients_.size(); i++) {
            if (i > 0) {
                result << " + ";
            }

            result << coefficients_[i] << "*x^" << i;
        }

        return result.str();
    }

private:
    std::vector<T> coefficients_;
};

// ==================== Template class med sort, back, max_element og T{} ====================

template <typename T>
class MeasurementsTemplate {
public:
    void add(T value) {
        data_.push_back(value);
    }

    T average() const {
        if (data_.empty()) {
            throw std::length_error("Ingen målinger");
        }

        T sum{};
        for (const auto& value : data_) {
            sum = sum + value;
        }

        return sum / static_cast<double>(data_.size());
    }

    T latest() const {
        if (data_.empty()) {
            throw std::length_error("Ingen seneste måling");
        }

        return data_.back();
    }

    std::vector<T> sorted() const {
        std::vector<T> copy = data_;
        std::sort(copy.begin(), copy.end());
        return copy;
    }

    T max() const {
        if (data_.empty()) {
            throw std::length_error("Ingen max måling");
        }

        return *std::max_element(data_.begin(), data_.end());
    }

private:
    std::vector<T> data_;
};

// ==================== std::pair, emplace_back og private hjælpefunktion ====================

class LocationExample {
public:
    LocationExample(double longitude, double latitude);

    bool operator==(const LocationExample& other) const;

    double longitude;
    double latitude;
};

template <typename T>
class NetworkExample {
public:
    void addNode(const T& node) {
        nodes_.push_back(node);
    }

    void addConnection(const T& first, const T& second) {
        const T* firstPtr = findNode(first);
        const T* secondPtr = findNode(second);

        if (firstPtr == nullptr || secondPtr == nullptr) {
            throw std::invalid_argument("Node findes ikke");
        }

        if (first == second) {
            throw std::invalid_argument("En node må ikke forbindes til sig selv");
        }

        for (const auto& connection : connections_) {
            const bool sameDirection = connection.first == firstPtr && connection.second == secondPtr;
            const bool oppositeDirection = connection.first == secondPtr && connection.second == firstPtr;

            if (sameDirection || oppositeDirection) {
                throw std::invalid_argument("Forbindelsen findes allerede");
            }
        }

        connections_.emplace_back(firstPtr, secondPtr);
    }

    std::vector<T> getAllNeighbours(const T& node) const {
        const T* nodePtr = findNode(node);
        std::vector<T> neighbours;

        for (const auto& connection : connections_) {
            if (connection.first == nodePtr) {
                neighbours.push_back(*connection.second);
            }

            if (connection.second == nodePtr) {
                neighbours.push_back(*connection.first);
            }
        }

        return neighbours;
    }

private:
    const T* findNode(const T& node) const {
        for (const auto& current : nodes_) {
            if (current == node) {
                return &current;
            }
        }

        return nullptr;
    }

    std::vector<T> nodes_;
    std::vector<std::pair<const T*, const T*>> connections_;
};

// ==================== Template method pattern med protected pure virtual methods ====================

class DataCollector {
public:
    virtual ~DataCollector();

    void receive(double value);
    std::string print() const;

protected:
    virtual void collect(double value) = 0;
    virtual std::vector<double> prepare() const = 0;
    virtual bool filter(double value) const = 0;
    virtual std::string format(double value) const = 0;
};

class UniqueSortedCollector : public DataCollector {
protected:
    void collect(double value) override;
    std::vector<double> prepare() const override;

private:
    std::set<double> data_;
};

class CsvUniqueSortedCollector : public UniqueSortedCollector {
public:
    explicit CsvUniqueSortedCollector(double upperLimit);

protected:
    bool filter(double value) const override;
    std::string format(double value) const override;

private:
    double upperLimit_;
};

class JsonCollector : public DataCollector {
public:
    JsonCollector(std::string valueName, double lowerLimit, double upperLimit);

protected:
    void collect(double value) override;
    std::vector<double> prepare() const override;
    bool filter(double value) const override;
    std::string format(double value) const override;

private:
    std::string valueName_;
    std::pair<double, double> range_;
    std::vector<double> data_;
};

// ==================== Vector af base-class pointers ====================

class Loan {
public:
    virtual ~Loan();

    std::string getPaymentScheme() const;

protected:
    Loan(std::string name, double principal, double interestRate, unsigned int terms);

    virtual double getPayment(unsigned int term) const = 0;

    double getTotalPayment() const;
    double getPrincipal() const;
    double getRate() const;
    unsigned int getTerms() const;
    std::string getName() const;

private:
    std::string name_;
    double principal_;
    double interestRate_;
    unsigned int terms_;
};

class SerialLoan : public Loan {
public:
    SerialLoan(std::string name, double principal, double interestRate, unsigned int terms);

protected:
    double getPayment(unsigned int term) const override;
};

class AnnuityLoan : public Loan {
public:
    AnnuityLoan(std::string name, double principal, double interestRate, unsigned int terms);

protected:
    double getPayment(unsigned int term) const override;

private:
    double payment_;
    static double calculatePayment(double principal, double interestRate, unsigned int terms);
};

class Account {
public:
    void addLoan(Loan* loan);
    std::string allSchemes() const;

private:
    std::vector<Loan*> loans_;
};

// ==================== = default special members ====================

class DefaultedAmplifier {
public:
    DefaultedAmplifier() = default;
    DefaultedAmplifier(const DefaultedAmplifier&) = default;
    DefaultedAmplifier& operator=(const DefaultedAmplifier&) = default;
    virtual ~DefaultedAmplifier() = default;

    virtual void amplify(double& value) const = 0;
};

class GainAmplifier : public DefaultedAmplifier {
public:
    explicit GainAmplifier(double gain);

    void amplify(double& value) const override;

private:
    double gain_;
};

// ==================== Kædede metodekald med return *this ====================

class FilterTransform {
public:
    virtual ~FilterTransform() = default;

    virtual double transform(double value) const = 0;
};

class LowPassFilter : public FilterTransform {
public:
    explicit LowPassFilter(double threshold);

    double transform(double value) const override;

private:
    double threshold_;
};

class HighPassFilter : public FilterTransform {
public:
    explicit HighPassFilter(double threshold);

    double transform(double value) const override;

private:
    double threshold_;
};

class DataSequence {
public:
    void add(double value);
    const std::vector<double>& getData() const;
    DataSequence& applyFilter(const FilterTransform& filter);

    friend std::ostream& operator<<(std::ostream& os, const DataSequence& dataSequence);

private:
    std::vector<double> data_;
};

// ==================== list::sort i egen priority queue ====================

class PriorityPerson {
public:
    PriorityPerson(std::string name, int priority);

    friend bool operator<(const PriorityPerson& left, const PriorityPerson& right);
    friend std::ostream& operator<<(std::ostream& os, const PriorityPerson& person);

private:
    std::string name_;
    int priority_;
};

template <typename T>
class PriorityListQueue {
public:
    void push(const T& value) {
        queue_.push_front(value);
        queue_.sort();
    }

    void pop() {
        queue_.pop_back();
    }

    T peek() const {
        return queue_.back();
    }

    bool empty() const {
        return queue_.empty();
    }

private:
    std::list<T> queue_;
};

// ==================== Mutable string reference + polymorf behandling ====================

class StringProcessor {
public:
    virtual ~StringProcessor() = default;

    virtual void process(std::string& text) const = 0;
};

class ToUpperCaseProcessor : public StringProcessor {
public:
    void process(std::string& text) const override;
};

class RemoveCharProcessor : public StringProcessor {
public:
    explicit RemoveCharProcessor(char character);

    void process(std::string& text) const override;

private:
    char character_;
};

class Document {
public:
    explicit Document(std::string text);

    void add(StringProcessor* processor);
    void process();

    friend std::ostream& operator<<(std::ostream& os, const Document& document);

private:
    std::vector<StringProcessor*> processors_;
    std::string text_;
};

// ==================== Valuta conversion + friend operator== ====================

class Currency {
public:
    Currency(std::string symbol, double factor);

    double toStandardCurrency(double amount) const;
    double fromStandardCurrency(double amount) const;
    std::string getSymbol() const;

private:
    std::string symbol_;
    double factor_;
};

class Amount {
public:
    Amount(double amount, Currency currency);

    Amount operator+(const Amount& right) const;
    std::string toString() const;

    friend bool operator==(const Amount& left, const Amount& right);

private:
    double amount_;
    Currency currency_;
};

// ==================== inline friend operator i header ====================

class ComplexNumber {
public:
    explicit ComplexNumber(double real = 0.0, double imaginary = 0.0)
        : real_{real}, imaginary_{imaginary} {
    }

    ComplexNumber operator+(const ComplexNumber& right) const {
        return ComplexNumber{real_ + right.real_, imaginary_ + right.imaginary_};
    }

    ComplexNumber operator*(const ComplexNumber& right) const {
        return ComplexNumber{real_ * right.real_ - imaginary_ * right.imaginary_,
                             real_ * right.imaginary_ + imaginary_ * right.real_};
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& number) {
        os << "R:" << number.real_ << " Im:" << number.imaginary_;
        return os;
    }

private:
    double real_;
    double imaginary_;
};

// ==================== Iterator med vector ====================

class VectorIteratorExample {
public:
    VectorIteratorExample();

    void addNumber(int number);
    void printWithIterator() const;
    void changeWithIterator();

private:
    std::vector<int> numbers_;
};

// ==================== Const iterator med vector ====================

class ConstIteratorExample {
public:
    ConstIteratorExample();

    void addName(const std::string& name);
    void printWithConstIterator() const;

private:
    std::vector<std::string> names_;
};

// ==================== Iterator med map ====================

class MapIteratorExample {
public:
    MapIteratorExample();

    void addGrade(const std::string& name, int grade);
    void printGrades() const;
    void increaseGrades();

private:
    std::map<std::string, int> grades_;
};

// ==================== Iterator med find ====================

class FindIteratorExample {
public:
    FindIteratorExample();

    void addNumber(int number);
    bool containsNumber(int number) const;

private:
    std::vector<int> numbers_;
};

// ==================== Iterator med erase ====================

class EraseIteratorExample {
public:
    EraseIteratorExample();

    void addNumber(int number);
    void removeNumber(int number);
    void printNumbers() const;

private:
    std::vector<int> numbers_;
};

#endif