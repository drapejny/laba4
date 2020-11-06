import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        String s = scn.nextLine();
        System.out.println(infixToPrefix(s));
    }


    static boolean isOperator(char c) {
        switch (c) {

            case '(':
                return true;
            case ')':
                return true;
            case '+':
                return true;
            case '-':
                return true;
            case '*':
                return true;
            case '/':
                return true;
            case '^':
                return true;
            default:
                return false;
        }
    }


    static int getPriority(char C) {
        if (C == '-' || C == '+')
            return 1;
        else if (C == '*' || C == '/')
            return 2;
        else if (C == '^')
            return 3;
        return 0;
    }


    static String infixToPrefix(String infix) {

        Stack<Character> operators = new Stack<Character>();

        Stack<String> operands = new Stack<String>();

        for (int i = 0; i < infix.length(); i++) {

            if (infix.charAt(i) == '(') {
                operators.push(infix.charAt(i));
            }


            //если текущий символ ')' , то выталкиваем из обоих стеков 2
            //операнда и оператор и результат заносим в стек операндов
            else if (infix.charAt(i) == ')') {
                while (!operators.empty() && operators.peek() != '(') {

                    String op1 = operands.peek();
                    operands.pop();

                    String op2 = operands.peek();
                    operands.pop();

                    char op = operators.peek();
                    operators.pop();

                    String tmp = op + op2 + op1;
                    operands.push(tmp);
                }

                //выпихиваем '('
                operators.pop();
            }

            // если операнд
            else if (!isOperator(infix.charAt(i))) {
                operands.push(infix.charAt(i) + "");
            }
            // если оператор
            else {
                while (!operators.empty() && getPriority(infix.charAt(i)) <= getPriority(operators.peek())) {

                    String op1 = operands.peek();
                    operands.pop();

                    String op2 = operands.peek();
                    operands.pop();

                    char op = operators.peek();
                    operators.pop();

                    String tmp = op + op2 + op1;
                    operands.push(tmp);
                }

                operators.push(infix.charAt(i));
            }
        }


         //извлекаем операторы из стека операторов до момента , когда он будет
         //пуст и добавляем в стек операндов для результата.

        while (!operators.empty()) {
            String op1 = operands.peek();
            operands.pop();

            String op2 = operands.peek();
            operands.pop();

            char op = operators.peek();
            operators.pop();

            String tmp = op + op2 + op1;
            operands.push(tmp);
        }
        //результат
        return operands.peek();
    }


}
