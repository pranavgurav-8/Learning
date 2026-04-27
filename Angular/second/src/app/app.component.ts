import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { IEmployee } from './appInterfaces.ts/IEmployee';

@Component({
  selector: 'pranav',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title:string = 'Hello Pranav';
  name:string = 'Pranav'

  employee!:IEmployee;
  // employee:any = {
  //   name: 'Pranav',
  //   age: 23,
  //   status: true,
  // }

  ngOnInit() {
    // this.employee.age = 23;
    // var empName:string = 'john';
    // empName = 342;
    // console.log(empName);
    // // console.log("employee is ",this.employee);

    // setTimeout(() => {
    //   this.employee = {
    //     name: 'Pranav',
    //     age: 23,
    //     status: true,
    //   };
    //   // console.log("employee is ",this.employee);
    // }, 2000);

    // this.calculateSum(this.num1, this.num2, this.num3);
    this.calculateSum(10, 20, 30);
  }
  
  num1:number = 10;
  num2:number = 20;
  num3:number = 30;

  calculateSum(num1:number, num2:number, num3?:number) {
    if(typeof num3 !== 'undefined') {
        console.log("sum => ",num1 + num2 + num3);  
    } else {
        console.log("sum => ",num1 + num2);  
    }
  }
}
