using System.ComponentModel.Design;
using System.Dynamic;
using System.Security.Cryptography.X509Certificates;

namespace Escola.Models;

public class Student{
    public int Id {get;set;}

    public string Name {get;set;} = "";

    public string Email { get; set; } = "";

    public DateTime EnrollnextDate {get;set;} = DateTime.UtcNow;
}
