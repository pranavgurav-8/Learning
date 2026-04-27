import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'DynamicStyling';
  bgcolor = 'green';
  fontSize = '50';
  headingSizeBig="100px";
  headingSizeSmall="30px";  

  bigTheme = false;
  updateHeadingSize() {   
    this.bigTheme = !this.bigTheme;
  }
}
