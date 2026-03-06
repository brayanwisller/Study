package Atividade2;

public class Emprego {
    private String nome;
    private String sobrenome;
    private double salario_mensal;

    public Emprego(String nome, String sobrenome, double salario_mensal){
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.salario_mensal = salario_mensal;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return nome;
    }
    public void setSobrenome(String sobrenome){
        this.sobrenome = sobrenome;
    }
    public String getSobrenome(){
        return sobrenome;
    }
    public void setSalarioMensal(double salario_mensal){
        this.salario_mensal = salario_mensal;
    }
    public double getSalarioMensal(){
        return salario_mensal;
    }

public double getSalarioAnual(){
    return salario_mensal * 12;
}

public void Aumento(){
    salario_mensal *= 1.1;
}

public String toString(){
    return "Nome: " + nome + "\nSobrenome: " + sobrenome +
           "\nSalario Mensal: " + salario_mensal;
}
}
