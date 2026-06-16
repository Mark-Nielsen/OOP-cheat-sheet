#include "OOP_Eksamen_Eksempler.h"

int main() {
    // ==================== Nyere C++ syntaks ====================
    ModernSyntaxExample modern;
    auto value = modern.getValue();
    std::cout << "Modern value: " << value << "\n";
    modern.printValues();

    // ==================== Pointere ====================
    int number = 5;
    PointerBox pointerBox;
    pointerBox.setPointer(&number);
    pointerBox.changeValueThroughPointer(20);
    pointerBox.printPointerValue();

    // ==================== L-value referencer ====================
    ReferenceChanger changer;
    changer.increase(number);
    std::cout << number << "\n";

    int a = 1;
    int b = 2;
    changer.swapValues(a, b);
    std::cout << a << " " << b << "\n";

    std::string oldName = "Gammelt navn";
    changer.rename(oldName);
    std::cout << oldName << "\n";

    // ==================== const ====================
    const ConstStudent student{"Mark", 22};
    std::cout << student.getName() << " " << student.getAge() << "\n";

    // ==================== Default copy constructor ====================
    DefaultCopyPerson p1{"Anna", 20};
    DefaultCopyPerson p2 = p1;
    p2.setAge(21);
    p1.print();
    p2.print();

    // ==================== Assignment ====================
    AssignmentCar car1{"Toyota", 2020};
    AssignmentCar car2{"BMW", 2022};
    car2 = car1;
    car2.print();

    // ==================== Composition ====================
    CompositionCar compositionCar{"Volvo", 150};
    compositionCar.startCar();

    // ==================== Association ====================
    Teacher teacher{"Peter"};
    Course course{"OOP"};
    course.setTeacher(&teacher);
    course.printInfo();

    // ==================== Andre klasserelationer ====================
    Driver driver{"Mark"};
    driver.addLicense(License{"B"});
    driver.addLicense(License{"BE"});
    driver.printLicenses();

    // ==================== Static members ====================
    StaticCounter c1;
    StaticCounter c2;
    std::cout << StaticCounter::getCount() << "\n";

    // ==================== Errors ====================
    ErrorExample errorExample;
    int result = 0;
    if (errorExample.divide(10, 2, result)) {
        std::cout << result << "\n";
    }

    if (!errorExample.setAge(-1)) {
        std::cout << errorExample.getLastError() << "\n";
    }

    // ==================== Exceptions ====================
    BankAccount account{100};
    try {
        account.withdraw(50);
        std::cout << account.getBalance() << "\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }

    // ==================== Debugging ====================
    DebugExample debug;
    debug.printDebugInfo("Programmet kører");
    std::cout << debug.calculateTotal(std::vector<int>{1, 2, 3}) << "\n";

    // ==================== Memory management ====================
    MemoryManager memoryManager;
    memoryManager.useSmartPointer();
    memoryManager.useVectorMemory();

    // ==================== new/delete ====================
    DynamicNumber dynamicNumber;
    int* dynamicValue = dynamicNumber.createNumber(99);
    std::cout << *dynamicValue << "\n";
    dynamicNumber.deleteNumber(dynamicValue);

    // ==================== Destructors ====================
    DestructorExample destructorExample{"Test"};
    destructorExample.print();

    // ==================== this pointer ====================
    ThisPointerExample thisExample{"Gammelt navn"};
    thisExample.setName("Nyt navn").printThisAddress();

    // ==================== Object life cycle ====================
    LifeCycleExample life{"Objekt"};
    LifeCycleExample lifeCopy = life;
    lifeCopy.print();

    // ==================== Rule of 3 ====================
    RuleOfThreeArray array{3};
    array.setValue(0, 42);
    std::cout << array.getValue(0) << "\n";

    RuleOfThreeArray arrayCopy = array;
    std::cout << arrayCopy.getValue(0) << "\n";

    // ==================== Operator overload ====================
    Vector2D v1{1, 2};
    Vector2D v2{3, 4};
    Vector2D v3 = v1 + v2;
    Vector2D v4 = -v1;
    v3.print();
    v4.print();
    std::cout << (v1 == v2) << "\n";

    // ==================== Friend functions ====================
    SecretNumber secret{123};
    SecretNumber secret2{123};
    printSecret(secret);
    std::cout << isSameSecret(secret, secret2) << "\n";

    // ==================== Template function ====================
    std::cout << getLargest<int>(4, 9) << "\n";
    std::cout << getLargest<std::string>("a", "b") << "\n";
    printTwice<std::string>("Hej");

    // ==================== Template class ====================
    StorageBox<int> box{10};
    std::cout << box.getValue() << "\n";
    box.setValue(20);
    std::cout << box.getValue() << "\n";

    // ==================== Templates fortsat ====================
    PairBox<int> pairBox{5, 8};
    std::cout << pairBox.getFirst() << " " << pairBox.getSecond() << "\n";
    std::cout << pairBox.getLargest() << "\n";

    // ==================== STL ====================
    StlVectorExample stl;
    stl.addNumber(1);
    stl.addNumber(2);
    std::cout << stl.getSum() << "\n";
    stl.printNumbers();

    // ==================== STL fortsat ====================
    StlObjectCollection collection;
    collection.addStudent(ConstStudent{"Ida", 21});
    collection.printStudents();
    std::cout << collection.getAmount() << "\n";

    // ==================== Inheritance ====================
    Dog dog{"Fido"};
    dog.eat();
    dog.bark();

    // ==================== Virtual metode med override ====================
    Cat cat{"Misser"};
    printAnimalSound(dog);
    printAnimalSound(cat);

    // ==================== Polymorfi / pure virtual metode ====================
    Rectangle rectangle{4, 5};
    Circle circle{3};
    printShapeInfo(rectangle);
    printShapeInfo(circle);

    // ==================== Virtual metode brugt med pointer/reference ====================
    HourlyEmployee hourlyEmployee{"Timelønnet", 10, 150};
    FixedEmployee fixedEmployee{"Fastlønnet", 30000};
    printEmployeePay(hourlyEmployee);
    printEmployeePay(fixedEmployee);

    // ==================== Streaming operator med friend function ====================
    Person person{"Mark", 22};
    std::cout << person << "\n";

    // ==================== Streaming operator uden friend function ====================
    Point point{2.5, 4.5};
    std::cout << point << "\n";

    // ==================== Streaming operator med STL vector ====================
    Team team{"Hold A"};
    team.addPlayer("Mark");
    team.addPlayer("Anna");
    std::cout << team << "\n";

    // ==================== Eksempel: syntax til forskellige STL containers ====================
    ContainerExamples containers;
    containers.vectorExample();
    containers.listExample();
    containers.dequeExample();
    containers.arrayExample();
    containers.setExample();
    containers.mapExample();
    containers.unorderedMapExample();
    containers.stackExample();
    containers.queueExample();
    containers.priorityQueueExample();

    // ==================== Hvad returneres hvornår ====================
    LimitChecker limitChecker{0, 10};
    std::cout << limitChecker.isBelowLimit(5) << "\n";
    std::cout << limitChecker.isAboveLimit(15) << "\n";
    std::cout << limitChecker.isInsideLimits(7) << "\n";

    // ==================== Eksempel 1: Exception ved division ====================
    Divider divider;
    try {
        std::cout << divider.divide(10, 2) << "\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }

    // ==================== Eksempel 2: Exception ved ugyldig alder ====================
    PersonValidator validator;
    try {
        validator.setAge(22);
        std::cout << validator.getAge() << "\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }

    // ==================== Eksempel 3: Exception ved ugyldigt index ====================
    NumberList numberList;
    numberList.addNumber(100);
    numberList.addNumber(200);
    try {
        std::cout << numberList.getNumberAt(1) << "\n";
    } catch (const std::exception& error) {
        std::cout << error.what() << "\n";
    }

    // ==================== try & catch ====================
    tryCatchExample();

    // ==================== to_string uden slut komma ====================
    Boxes boxes;
    boxes.addBox(SimpleBox{2});
    boxes.addBox(SimpleBox{3});
    boxes.addBox(SimpleBox{4});
    std::cout << boxes.to_string() << "\n";


        // ==================== explicit constructor + default argument ====================
    TemperatureValue t1{20};
    TemperatureValue t2;
    TemperatureValue t3 = t1 + t2;
    std::cout << t3 << "\n";
    std::cout << t1.toFahrenheit() << "\n";
    std::cout << (t1 > t2) << "\n";

    // ==================== inline static member ====================
    CapacitorExample capacitor1{100E-6};
    CapacitorExample capacitor2{200E-6};
    std::cout << capacitor1 << "\n";
    std::cout << (capacitor1 | capacitor2) << "\n";
    std::cout << (capacitor1 & capacitor2) << "\n";

    // ==================== Flere operator overloads: *, &&, <, >, / ====================
    Matrix2x2 matrix1{1, 2, 3, 4};
    Matrix2x2 matrix2{2, 0, 1, 2};
    std::cout << matrix1 * matrix2 << "\n";
    CircleIntersectExample circle1{Point{0, 0}, 5};
    CircleIntersectExample circle2{Point{4, 0}, 2};
    std::cout << (circle1 && circle2) << "\n";
    std::cout << (circle1 * 2) << "\n";

    // ==================== operator() function call ====================
    Polynomial polynomial{{1, 2, 3}};
    Polynomial polynomial2{{10, 20}};
    std::cout << polynomial(2) << "\n";
    std::cout << (polynomial + polynomial2).toString() << "\n";

    // ==================== Template class med operator() ====================
    PolynomialTemplate<int> templatePolynomial{{1, 2, 3}};
    std::cout << templatePolynomial(2) << "\n";
    std::cout << templatePolynomial.toString() << "\n";

    // ==================== Template class med sort, back, max_element og T{} ====================
    MeasurementsTemplate<TemperatureValue> measurements;
    measurements.add(TemperatureValue{10});
    measurements.add(TemperatureValue{30});
    measurements.add(TemperatureValue{20});
    std::cout << measurements.average() << "\n";
    std::cout << measurements.latest() << "\n";
    std::cout << measurements.max() << "\n";
    for (const auto& temperature : measurements.sorted()) {
        std::cout << temperature << " ";
    }
    std::cout << "\n";

    // ==================== std::pair, emplace_back og private hjælpefunktion ====================
    LocationExample l1{1, 1};
    LocationExample l2{1, 2};
    LocationExample l3{2, 1};
    NetworkExample<LocationExample> network;
    network.addNode(l1);
    network.addNode(l2);
    network.addNode(l3);
    network.addConnection(l1, l2);
    network.addConnection(l1, l3);
    std::cout << network.getAllNeighbours(l1).size() << "\n";

    // ==================== Template method pattern med protected pure virtual methods ====================
    CsvUniqueSortedCollector csvCollector{200};
    csvCollector.receive(53);
    csvCollector.receive(5);
    csvCollector.receive(53);
    csvCollector.receive(300);
    std::cout << csvCollector.print();

    JsonCollector jsonCollector{"temperature", 3, 200};
    jsonCollector.receive(53);
    jsonCollector.receive(2);
    std::cout << jsonCollector.print();

    // ==================== Vector af base-class pointers ====================
    SerialLoan serialLoan{"Serial", 1000, 0.03, 3};
    AnnuityLoan annuityLoan{"Annuitet", 1000, 0.03, 3};
    Account loanAccount;
    loanAccount.addLoan(&serialLoan);
    loanAccount.addLoan(&annuityLoan);
    std::cout << loanAccount.allSchemes() << "\n";

    // ==================== = default special members ====================
    double signalValue = 5;
    GainAmplifier gain{2};
    gain.amplify(signalValue);
    std::cout << signalValue << "\n";

    // ==================== Kædede metodekald med return *this ====================
    DataSequence dataSequence;
    for (int i = 0; i <= 10; i++) {
        dataSequence.add(i);
    }
    LowPassFilter lowPass{8};
    HighPassFilter highPass{4};
    dataSequence.applyFilter(lowPass).applyFilter(highPass);
    std::cout << dataSequence << "\n";

    // ==================== list::sort i egen priority queue ====================
    PriorityListQueue<PriorityPerson> priorityQueue;
    priorityQueue.push(PriorityPerson{"Lav", 1});
    priorityQueue.push(PriorityPerson{"Høj", 10});
    std::cout << priorityQueue.peek() << "\n";
    priorityQueue.pop();
    std::cout << priorityQueue.peek() << "\n";

    // ==================== Mutable string reference + polymorf behandling ====================
    ToUpperCaseProcessor upperCase;
    RemoveCharProcessor removeE{'E'};
    Document document{"Example Text"};
    document.add(&upperCase);
    document.add(&removeE);
    std::cout << document << "\n";
    document.process();
    std::cout << document << "\n";

    // ==================== Valuta conversion + friend operator== ====================
    Currency dollar{"Dollar", 0.92};
    Currency pound{"Pound", 1.18};
    Amount dollarAmount{1000, dollar};
    Amount poundAmount{1000, pound};
    std::cout << (dollarAmount + poundAmount).toString() << "\n";
    std::cout << (dollarAmount == poundAmount) << "\n";

    // ==================== inline friend operator i header ====================
    ComplexNumber complex1{1, 2};
    ComplexNumber complex2{3, 4};
    std::cout << complex1 + complex2 << "\n";
    std::cout << complex1 * complex2 << "\n";
    
 // ==================== Iterator med vector ====================

    VectorIteratorExample vectorExample;

    vectorExample.addNumber(10);
    vectorExample.addNumber(20);
    vectorExample.addNumber(30);

    vectorExample.printWithIterator();

    vectorExample.changeWithIterator();

    vectorExample.printWithIterator();

    // ==================== Const iterator med vector ====================

    ConstIteratorExample constExample;

    constExample.addName("Mark");
    constExample.addName("Anna");
    constExample.addName("Jonas");

    constExample.printWithConstIterator();

    // ==================== Iterator med map ====================

    MapIteratorExample mapExample;

    mapExample.addGrade("Mark", 7);
    mapExample.addGrade("Anna", 10);
    mapExample.addGrade("Jonas", 12);

    mapExample.printGrades();

    mapExample.increaseGrades();

    mapExample.printGrades();

    // ==================== Iterator med find ====================

    FindIteratorExample findExample;

    findExample.addNumber(5);
    findExample.addNumber(10);
    findExample.addNumber(15);

    if (findExample.containsNumber(10)) {
        std::cout << "10 findes\n";
    }

    if (!findExample.containsNumber(99)) {
        std::cout << "99 findes ikke\n";
    }

    // ==================== Iterator med erase ====================

    EraseIteratorExample eraseExample;

    eraseExample.addNumber(1);
    eraseExample.addNumber(2);
    eraseExample.addNumber(3);

    eraseExample.printNumbers();

    eraseExample.removeNumber(2);

    eraseExample.printNumbers();

    return 0;
}

   