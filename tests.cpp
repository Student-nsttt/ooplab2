#include <gtest/gtest.h>
#include <utility> 
#include "polynomial.h"

class PolynomialTest : public ::testing::Test {
protected:
    // Просто целые числа, записанные через точку
    double arr_3_elements[3] = {1.0, 2.0, 3.0}; 
    double arr_2_elements[2] = {5.0, -2.0};        
};

// 1. Пустой объект
TEST_F(PolynomialTest, Test_Empty_Object) {
    Polynomial p;
    EXPECT_EQ(p.get_degree(), -1);
    EXPECT_EQ(p.evaluate(5), 0);
}

// 2. Создание из массива
TEST_F(PolynomialTest, Test_Create_From_Array) {
    Polynomial p(arr_3_elements, 3);
    EXPECT_EQ(p.get_degree(), 2);
}

// 3. Создание с плохим размером
TEST_F(PolynomialTest, Test_Create_With_Negative_Size) {
    Polynomial p(arr_3_elements, -5);
    EXPECT_EQ(p.get_degree(), -1);
}

// 4. Подсчет значения Evaluate
TEST_F(PolynomialTest, Test_Evaluate_Math) {
    Polynomial p(arr_3_elements, 3);
    EXPECT_EQ(p.evaluate(5), 86);
    EXPECT_EQ(p.evaluate(0), 1);
}

// 5. Интеграл от 0 до 2
TEST_F(PolynomialTest, Test_Integral_From_0_To_2) {
    Polynomial p(arr_3_elements, 3);
    EXPECT_EQ(p.definite_integral(0, 2), 14);
}

// 6. Интеграл от 3 до 3
TEST_F(PolynomialTest, Test_Integral_Same_Points) {
    Polynomial p(arr_3_elements, 3);
    EXPECT_EQ(p.definite_integral(3, 3), 0);
}

// 7. Конструктор копирования
TEST_F(PolynomialTest, Test_Copy_Constructor) {
    Polynomial p1(arr_3_elements, 3);
    Polynomial p2 = p1;
    EXPECT_EQ(p2.get_degree(), 2);
    EXPECT_EQ(p2.evaluate(5), 86);
}

// 8. Копирование пустого объекта
TEST_F(PolynomialTest, Test_Copy_Empty_Object) {
    Polynomial p1;
    Polynomial p2 = p1;
    EXPECT_EQ(p2.get_degree(), -1);
}

// 9. Перемещение Move
TEST_F(PolynomialTest, Test_Move_Constructor) {
    Polynomial p1(arr_3_elements, 3);
    Polynomial p2 = std::move(p1);
    
    EXPECT_EQ(p2.get_degree(), 2);
    EXPECT_EQ(p2.evaluate(5), 86);
    EXPECT_EQ(p1.get_degree(), -1); 
}

// 10. Обмен данными Swap
TEST_F(PolynomialTest, Test_Swap_Method) {
    Polynomial p1(arr_3_elements, 3);
    Polynomial p2(arr_2_elements, 2);
    
    p1.swap(p2);
    
    EXPECT_EQ(p1.get_degree(), 1);
    EXPECT_EQ(p2.get_degree(), 2);
}

// 11. Обычное присваивание через знак равенства
TEST_F(PolynomialTest, Test_Assignment_Operator) {
    Polynomial p1(arr_3_elements, 3);
    Polynomial p2;
    p2 = p1;
    EXPECT_EQ(p2.get_degree(), 2);
    EXPECT_EQ(p2.evaluate(5), 86);
}

// 12. Присваивание самого себя
TEST_F(PolynomialTest, Test_Self_Assignment) {
    Polynomial p(arr_3_elements, 3);
    p = p;
    EXPECT_EQ(p.get_degree(), 2);
    EXPECT_EQ(p.evaluate(5), 86);
}

