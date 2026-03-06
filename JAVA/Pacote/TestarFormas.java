import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class TestarFormas {
    public static void main (String [] args){
        Scanner scanner = new Scanner(System.in);
        List<FormaGeometrica> formas = new ArrayList<>();

        System.out.println("Quantas formas geometricas deseja criar?");

        int quantidade = scanner.nextInt();

        for(int i = 0; i < quantidade; i++){
            System.out.println("\nEscolha uma das formas geometricas abaixo:\n\n 1. Retângulo\n 2. Quadrado\n 3. Circulo\n");

            int opção = scanner.nextInt();

            switch(opção){
                case 1:
                System.out.println("\nQual a altura do retângulo?");
                double altura = scanner.nextDouble();
                System.out.println("\nQual a base do retângulo?");
                double base = scanner.nextDouble();
                formas.add(new Retangulo(base, altura));
                break;

                case 2:
                System.out.println("\nQual o lado do quadrado?");
                double lado = scanner.nextDouble();
                formas.add(new Quadrado(lado));
                break;

                case 3:
                System.out.println("\nQual o raio do circulo?");
                double raio = scanner.nextDouble();
                formas.add(new Circulo(raio));
                break;

                default:
                System.out.println("\nOpção Inválida!");
                i--;
                break;
            }
        }

        System.out.println("\n\n-----Dados, Perímetros e Áreas-----\n\n");

        for(FormaGeometrica forma : formas){
            if(formas instanceof Quadrado){
                Quadrado quadrado = (Quadrado) forma;

                System.out.println("\n\n-----Quadrado-----\n\n");
                System.out.println("Lados = " + quadrado.getLados());
                System.out.println("Perímetro = " + quadrado.calcularPerimetro());
                System.out.println("Área = " + quadrado.calcularArea());

            } else if (formas instanceof Retangulo){
                Retangulo retangulo = (Retangulo) forma;

                System.out.println("\n\n-----Retângulo-----\n\n");
                System.out.println("Altura = " + retangulo.getAltura());
                System.out.println("Base = " + retangulo.getBase());
                System.out.println("Perímetro = " + retangulo.calcularPerimetro());
                System.out.println("Área = " + retangulo.calcularArea());

            } else if (formas instanceof Circulo){
                Circulo circulo = (Circulo) forma;

                System.out.println("\n\n-----Circulo-----\n\n");
                System.out.println("Raio = " + circulo.getRaio());
                System.out.println("Perímetro = " + circulo.calcularPerimetro());
                System.out.println("Área = " + circulo.calcularArea());
            }

            System.out.println();
        }

        scanner.close();
    }
}
