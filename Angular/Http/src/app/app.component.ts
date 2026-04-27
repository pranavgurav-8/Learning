import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { UsersService } from './users.service';   

@Component({
  selector: 'app-root',
  imports: [RouterOutlet],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Http';
  constructor(private usersService: UsersService) {
    this.usersService.getUserData().subscribe(data => {
      console.log(data)
    })
  }
}
