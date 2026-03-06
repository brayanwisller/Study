package Atividade2;

public class TestarEmprego {
    public static void main(String[] args) {
        Emprego funcionario1 = new Emprego("Carlos", "Antonio", 2500.00);
        Emprego funcionario2 = new Emprego("Vinicius", "Junior", 4500.00);

        System.out.println("\n\n-----Funcionario 1-----\n\nSalario Anual: " + funcionario1.getSalarioAnual() + "\n\nDados: \n\n" + funcionario1.toString() +
                           "\n\n-----Funcionario 2-----\n\nSalario Anual: " + funcionario2.getSalarioAnual() + "\n\nDados: \n\n" + funcionario2.toString());

        funcionario1.Aumento();
        funcionario2.Aumento();
        
        System.out.println("\n\n-----Funcionario 1-----\n\nAumento de 10%\n\nSalario Anual: " + funcionario1.getSalarioAnual() + "\n\nDados: \n\n" + funcionario1.toString() +
                           "\n\n-----Funcionario 2-----\n\nAumento de 10%\n\nSalario Anual: " + funcionario2.getSalarioAnual() + "\n\nDados: \n\n" + funcionario2.toString());
    }
}
