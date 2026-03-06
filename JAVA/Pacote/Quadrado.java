public class Quadrado extends Retangulo{
    private double lado;

    public Quadrado(double lado){
        super(lado, lado);
        this.lado = lado;
    }

    public void setLados(double lado){
        this.lado = lado;
    }
    public double getLados(){
        return lado;
    }
}