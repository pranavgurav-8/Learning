import { Component,computed,effect,Signal,signal, WritableSignal } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { FormsModule } from '@angular/forms';
@Component({
  selector: 'app-root',
  imports: [RouterOutlet, FormsModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'ifelse';
  // display = false;
  color=2;

  users = ["John", "Jane", "Doe", "Alice", "Bob"];
  students = [{ name: "John", age: 20 },
    { name: "Jane", age: 22 },{ name: "Doe", age: 21 },
    { name: "Alice", age: 23 },{ name: "Bob", age: 24 }];

  getName(value:string) {
    console.log(value);
  }

  count = signal(10);
  x=20;

  constructor() {
    // this.count = 10; 
    effect(() => {
      console.log("Count changed:", this.count());
      console.log("User name changed:", this.userName());
    })
  }
  updateCount() {
    this.x =30;
    this.count.set(this.count() + 1);
}


//Data type Signals
data: WritableSignal<Number | string> = signal(19);
computedCount: Signal<number> = computed(() => 3)
updateData() {
  this.data.set("Hello");
  // this.computedCount.set(4); computed signals are read-only
  // this.data.set(20);
  // this.data.update(((val) => val+1));
  console.log(this.data());
}

//computed signals
a=signal(10);
b=signal(20);
c=computed(()=>this.a() + this.b());

showValue(){
  console.log(this.c());
  this.a.set(8);
  console.log(this.c());
}

//Two way binding
name = "Anil";

changeName(event:Event){
  const val = (event.target as HTMLInputElement).value;
  this.name = val;
}

userName = signal("Anil");

}
