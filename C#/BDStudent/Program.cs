using Microsoft.EntityFrameworkCore;

using Escola.Models;
using Escola.Data;


Console.WriteLine("--- Escola DB ---");
Console.WriteLine("Inicializando/Migrando o banco...");

var db = new AppDBContext();

await db.Database.MigrateAsync();

var name = "Léo";
var email = "leonardo@gmail.com";

var exists = await db.Students.AnyAsync(s=> s.Email == email);

if(exists){
    Console.WriteLine("Já existe um usuário com esse email");
    return;
}

var Student = new Student{
    Name = name,
    Email = email,
    EnrollnextDate = DateTime.UtcNow
};

db.Students.Add(Student);
await db.SaveChangesAsync();

Console.WriteLine($"Cadastro com sucesso! Id: {Student.Id}");

var lista_estudantes = await db.Students
    .OrderBy(s=> s.Id)
    .ToListAsync();

if(lista_estudantes.Count == 0){
    Console.WriteLine("Não há estudantes matriculados");
    return;
}

foreach(var s in lista_estudantes){
    Console.WriteLine($"{s.Id, 2} | {s.Name, -20} | {s.Email, -24} | {s.EnrollnextDate:yyyy-MM-dd HH:mm:ss}");
}