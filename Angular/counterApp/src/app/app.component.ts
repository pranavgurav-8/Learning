import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  count = 0;
  title = 'counterApp';
  increment() {
    this.count++;
    console.log("Incremented");
  }
  reset() {
    this.count = 0;
    console.log("Reseted");
  }
  decrement() {
    this.count--;
    console.log("Decremented");
  }
  handleCounter(val: string) {
    if (val == "increment") {
      this.increment();
    } else if (val == "decrement") {
      if (this.count > 0)
        this.decrement();
    } else {
      this.reset();
    }
  }
}
