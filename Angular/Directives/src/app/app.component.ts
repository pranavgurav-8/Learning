import { NgFor, NgIf } from '@angular/common';
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [NgIf,NgFor],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Directives';
  show = true;

  students = ["John", "Jane", "Doe", "Alice", "Bob"];
  studentsData = [
    { name: "John", age: 20, city: "New York"},
    { name: "Jane", age: 22, city: "Los Angeles"},
    { name: "Doe", age: 21, city: "Chicago"},
    { name: "Alice", age: 23, city: "Houston"},
    { name: "Bob", age: 24, city: "Phoenix"}
  ];
}
