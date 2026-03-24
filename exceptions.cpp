#include <iostream>

void func6();
void func5();
void func4();
void func3();
void func2();

void func6() {
    std::cout << "func6: throw double" << std::endl;
    throw 3.14;
}

void func5() {
    std::cout << "func5: start" << std::endl;
    try {
        func6();
    } catch (int) {
        throw;
    } catch (double) {
        throw;
    }
}

void func4() {
    std::cout << "func4: start" << std::endl;
    try {
        func5();
    } catch (int e) {
        std::cout << "func4: caught int" << std::endl;
    } catch (double) {
        throw;
    }
    std::cout << "func4: end" << std::endl;
}

void func3() {
    std::cout << "func3: start" << std::endl;
    try {
        func4();
    } catch (int e) {
        std::cout << "func3: caught int" << std::endl;
    } catch (double e) {
        std::cout << "func3: caught double" << std::endl;
    }
    std::cout << "func3: end" << std::endl;
}

void func2() {
    std::cout << "func2: start" << std::endl;
    func3();
    std::cout << "func2: end" << std::endl;
}