import { Component } from '@angular/core';
import { ProfileComponent } from '../profile/profile.component';

@Component({
  selector: 'app-contact',
  imports: [ProfileComponent],
  templateUrl: './contact.component.html',
  styleUrl: './contact.component.css'
})
export class ContactComponent {
  details: string[] = ["Name", "Email", "Phone"];
  currentTab: string = "";
  onTabChange(tabName: string) {
    debugger;
    this.currentTab = tabName;
    console.log("Tab clicked:", tabName);
  }
}
