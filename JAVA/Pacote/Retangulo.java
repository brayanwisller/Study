public class Retangulo extends Quadrilateros{
    private double base, altura;

    public Retangulo(double base, double altura){
        super(base, altura, base, altura);
        this.base = base;
        this.altura = altura;
    }

    public void setBase(double base){
        this.base = base;
    }
    public void setAltura(double altura){
        this.altura = altura;
    }

    public double getBase(){
        return base;
    }
    public double getAltura(){
        return altura;
    }

public double calcularArea(){
    return base * altura;
    }
}
